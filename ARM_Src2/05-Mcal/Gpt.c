/******************************************************************************************************************************
*	FILE DESCRIPTION
*	-------------------------------------------------------------------------------------------------------------------------
*				\File 	 : Gpt.c

*				\*brief	 :	Gpt Source File
*
*				\*details: define Global Timer API's    
*****************************************************************************************************************************/

/****************************************************************************************************************************

*	INCLUDES

****************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Gpt.h"
#include "Gpt_Config.h"
#include "Gpt_Private.h"


/****************************************************************************************************************************
*	GLOBAL FUNCTION PROTOTYPES
****************************************************************************************************************************/


/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to set Timer Configurations 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	const Gpt_ConfigType*ConfigPtr "Pointer to struct"
*	\Parameters (out):	void
*************************************************************************************************************************/


void Gpt_Init(const Gpt_ConfigType*ConfigPtr){
	
	Gpt_ChannelMaxTick[(ConfigPtr->Channel)]= ConfigPtr->GptChannelTickValueMax;   /*GPT CHANNEL MAX "ACT AS VALUE MASKING in ex:0xFFF"*/
	
	Gpt_callBackPtr[ConfigPtr->Channel] = ConfigPtr->Gpt_Notification;

	volatile Gpt_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[ConfigPtr->Channel];

	CLR_BIT(Gpt->GPTMCTL , 0 );                  /*disable timer*/

	Gpt->GPTMCFG = 0x04;                        /*No Concatanation*/ 
	
	Gpt->GPTMTAPR = ConfigPtr->GptChannelTickFrequency ;  /* set prescaler "(required Div-1)" and works as timer extension*/

	Gpt->GPTMIMR = 0x0000;                    /* disable all interrupts*/

	SET_BIT (Gpt->GPTMTAMR, 4);              /*timer count up*/


	switch (ConfigPtr->GptChannelMode){
	
	case ONE_SHOOT: 
		SET_BIT	(Gpt->GPTMTAMR, 0); break;
	
	case PERIODIC :
		SET_BIT	(Gpt->GPTMTAMR, 1);  break;
	
	default:
	
		break;
	}

}

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Disable Timer Interrupts in Run Time 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	Gpt_ChannelType Channel	"Timer ID "
*	\Parameters (out):	void
*************************************************************************************************************************/


void Gpt_DisableNotification(Gpt_ChannelType Channel){
	
	volatile Gpt_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[Channel];
	
	CLR_BIT(Gpt->GPTMIMR  , 0);
}

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Enable Timer Interrupts in Run Time 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	Gpt_ChannelType Channel	"Timer ID "
*	\Parameters (out):	void
*************************************************************************************************************************/

void Gpt_EnableNotification(Gpt_ChannelType Channel){
	
	volatile Gpt_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[Channel];

	SET_BIT(Gpt->GPTMIMR ,0);
	
}

/* #define Bit_Banding(PERIPHRAL_OFFSET , REGISTER_OFFSET , BIT_NUMBER)	((volatile uint32*)(BIT_BAND_ALIAS_BASE_ADDRESS + ((PERIPHRAL_OFFSET + REGISTER_OFFSET) * 32 )))[BIT_NUMBER]*/

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Start Timer Count 
*	\sync\Async      :	ASynchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Gpt_ChannelType Channel	"Timer ID " , Gpt_ValueType Value "No.of Counts in Tick"
*	\Parameters (out):	void
*************************************************************************************************************************/


void Gpt_StartTimer(Gpt_ChannelType Channel , Gpt_ValueType Value){

	volatile Gpt_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[Channel];

	volatile uint32 Gpt_Offset = TimerBaseAddress[Channel]-0x40000000;

	Gpt->GPTMTAILR=Value;

	BIT_BANDING( Gpt_Offset , 0x00C , 0 ) = 1;            /*SET_BIT( Gpt->GPTMCTL ,0).......start timer.*/

	while( BIT_BANDING( Gpt_Offset , 0x01C , 0) == 0); /*while(CHECK_BIT(GPTMRIS,0))*/ 
	
	BIT_BANDING(Gpt_Offset , 0x01C , 0)=1;			/*SET_BIT( Gpt->GPTMRIS , 0)*/
}

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Stop Timer Count 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Gpt_ChannelType Channel	"Timer ID " 
*	\Parameters (out):	void
*************************************************************************************************************************/

void Gpt_StopTimer(Gpt_ChannelType Channel){

	volatile Gpt_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[Channel];

	volatile uint32 Gpt_Offset = TimerBaseAddress[Channel]-0x40000000;

	BIT_BANDING(Gpt_Offset , 0x00C , 0)= 0;           /*CLR_BIT( Gpt->GPTMCTL ,0)........stop timer.*/

}

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Get Time Elapsed from Begaining of Count  
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Gpt_ChannelType Channel	"Timer ID " 
*	\Parameters (out):	Gpt_ValueType  "uint 32"
*************************************************************************************************************************/

Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel){

	volatile Gpt_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[Channel];

	Gpt_ValueType l_timerValue=0;
	
	uint16 l_counter=0;
	uint32 Gpt_Shifting = Gpt->GPTMTAPR;

	while(Gpt_Shifting !=0){

		Gpt_Shifting = Gpt_Shifting/2;
		l_counter++;
	} 	

	if(Channel <= 5){
		
		return (( Gpt->GPTMTAV >> l_counter )&(Gpt_ChannelMaxTick[Channel]));   /*TickValueMax!!!*/ 
		
	}
	
	else if(Channel <= 11){
	
		l_timerValue= ( Gpt->GPTMTAV >> l_counter )|(Gpt->GPTMTAPV<<(32-(l_counter)));
		
		l_timerValue= l_timerValue & Gpt_ChannelMaxTick[Channel];  /*TickValueMax!!!*/
		
		return l_timerValue;
	}

}

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to get Remaining Time 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Gpt_ChannelType Channel	"Timer ID "  
*	\Parameters (out):	Gpt_ValueType Value "No.of Counts in Tick"
*************************************************************************************************************************/

Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel){

	Gpt_ValueType l_timerValue=0;
	
	volatile Gpt_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[Channel];

	uint16 l_counter=0;
	uint16 Gpt_Shifting = Gpt->GPTMTAPR;

	while(Gpt_Shifting !=0){

		Gpt_Shifting = Gpt_Shifting/2;
		l_counter++;
	} 	


	if(Channel <= 5){
		
		return  ((((Gpt->GPTMTAILR)>>l_counter)-( (Gpt->GPTMTAV) >> l_counter ))  & Gpt_ChannelMaxTick[Channel]);
		
		
	}
	
	else if(Channel <= 11){
	
		l_timerValue=  (((Gpt->GPTMTAILR)>>l_counter)|( (Gpt->GPTMTAPR) << (32-l_counter) ))-((Gpt->GPTMTAV >> l_counter )|(Gpt->GPTMTAPV<<(32-l_counter)));
		
		l_timerValue= l_timerValue & Gpt_ChannelMaxTick[Channel];    /*TickValueMax!!!*/
		
		return l_timerValue;
	}
	
}


/* TIMER0_32_64 IS A PREDEFINED TIMER ASSUMING SYS CLOCK IS 16MHZ */

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Initialize the Predefined Timers which is defined before Run Time 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	Gpt_PredefTimerType PredefTimer "fixed Timer ID which is Timer0_32_64 "  
*	\Parameters (out):	void
*************************************************************************************************************************/

void Gpt_PredefTimerInit(Gpt_PredefTimerType PredefTimer){
	
	volatile Gpt_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[6];

	#if PREDEF_TIMER == PREDEF_GPT_ENABLE

		CLR_BIT(Gpt->GPTMCTL , 0 );                 /*disable timer*/

		Gpt->GPTMCFG = 0x04;                       /*No Concatanation*/ 
		
		Gpt->GPTMIMR = 0x0000;                    /* disable all interrupts*/

		SET_BIT (Gpt->GPTMTAMR, 4);              /*timer count up*/

		SET_BIT	(Gpt->GPTMTAMR, 1); 	          /*PERIODIC*/ 

		if(PredefTimer == GPT_PREDEF_TIMER_100US_32BIT){

				Gpt->GPTMTAPR = (0x063F)  ;  /* set prescaler "(required Div-1)" and works as timer extension*/
		}

		else{
				Gpt->GPTMTAPR = 0;
		}
	
		SET_BIT(Gpt->GPTMCTL , 0 );
	
	#endif	


}
	
/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to get the value of the Predefined Timers which is defined before Run Time 
*	\sync\Async      :	ASynchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	Gpt_PredefTimerType PredefTimer "fixed Timer ID which is Timer0_32_64 "  & uint32*TimeValuePtr "Pointer to recieve timer value"  
*	\Parameters (out):	l_timerValue
*	\Return          : std_ReturnType: E_OK
									   E_NOK
*************************************************************************************************************************/

Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer , uint32*TimeValuePtr){

	volatile Gpt_RegsType*Gpt= (volatile Gpt_RegsType*)TimerBaseAddress[6];

	Gpt_ValueType l_timerValue = 0;	
	
	#if PREDEF_TIMER == PREDEF_GPT_ENABLE

	switch(PredefTimer){
		
		case GPT_PREDEF_TIMER_100US_32BIT :       	 
			
				l_timerValue= (( Gpt->GPTMTAV >> 11 )|(Gpt->GPTMTAPV<<(32-11)));
		
				*TimeValuePtr= l_timerValue;

				return E_OK ;

	
		case GPT_PREDEF_TIMER_1US_16BIT :
	
			l_timerValue= ( Gpt->GPTMTAV >> 4 );
		
			l_timerValue= l_timerValue & (0xFFFF);  /*TickValueMax!!!*/
	
			*TimeValuePtr= l_timerValue;
		

			return E_OK ;

		case GPT_PREDEF_TIMER_1US_24BIT :
			 
			l_timerValue= ( Gpt->GPTMTAV >> 4 );
		
			l_timerValue= l_timerValue & (0xFFFFFF);
			
			*TimeValuePtr= l_timerValue;

			return E_OK;

		case GPT_PREDEF_TIMER_1US_32BIT :

			*TimeValuePtr= (Gpt->GPTMTAV >> 4);

			return E_OK;

		default:   

			return E_NOK;
		}

	#endif
		
}	

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  TIMER_ISR's 
*	\sync\Async      :	ASynchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	void
*	\Parameters (out):	void
*************************************************************************************************************************/

void TIMER0A_Handler(void){

	if(Gpt_callBackPtr[0] != NULL_PTR)
	{
		(*Gpt_callBackPtr[0])(); 
	}

}

void TIMER1A_Handler(void){

	if(Gpt_callBackPtr[1] != NULL_PTR)
	{
		(*Gpt_callBackPtr[1])(); 
	}

}

void TIMER2A_Handler(void){

	if(Gpt_callBackPtr[2] != NULL_PTR)
	{
		(*Gpt_callBackPtr[2])(); 
	}

}

void TIMER3A_Handler(void){

	if(Gpt_callBackPtr[3] != NULL_PTR)
	{
		(*Gpt_callBackPtr[3])(); 
	}

}

void TIMER4A_Handler(void){

	if(Gpt_callBackPtr[4] != NULL_PTR)
	{
		(*Gpt_callBackPtr[4])(); 
	}

}

void TIMER5A_Handler(void){

	if(Gpt_callBackPtr[5] != NULL_PTR)
	{
		(*Gpt_callBackPtr[5])(); 
	}

}

void WTIMER0A_Handler(void){

	if(Gpt_callBackPtr[6] != NULL_PTR)
	{
		(*Gpt_callBackPtr[6])(); 
	}

}

void WTIMER1A_Handler(void){

	if(Gpt_callBackPtr[7] != NULL_PTR)
	{
		(*Gpt_callBackPtr[7])(); 
	}

}

void WTIMER2A_Handler(void){

	if(Gpt_callBackPtr[8] != NULL_PTR)
	{
		(*Gpt_callBackPtr[8])(); 
	}

}

void WTIMER3A_Handler(void){

	if(Gpt_callBackPtr[9] != NULL_PTR)
	{
		(*Gpt_callBackPtr[9])(); 
	}

}

void WTIMER4A_Handler(void){

	if(Gpt_callBackPtr[10] != NULL_PTR)
	{
		(*Gpt_callBackPtr[10])(); 
	}

}

void WTIMER5A_Handler(void){

	if(Gpt_callBackPtr[11] != NULL_PTR)
	{
		(*Gpt_callBackPtr[11])(); 
	}

}

/***************************************************************************************************************************
*	END OF FILE :Gpt.c
***************************************************************************************************************************/
