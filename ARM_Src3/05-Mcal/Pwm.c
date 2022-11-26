/*****************************************************************************************************************************
*FILE DESCRIPTION
*-----------------------------------------------------------------------------------------------------------------------------
*		FILE: Pwm.c

*	Module:   PWM.c

*DESCRIPTION: Source file for PWM timer Periphral interface

*
*****************************************************************************************************************************/


/****************************************************************************************************************************

*	INCLUDES

*****************************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Pwm.h"
#include "Pwm_Private.h"


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

void Pwm_Init(const Pwm_ConfigType* ConfigPtr){
 
	
	volatile Gpt_RegsType*Pwm= (volatile Gpt_RegsType*)Pwm_TimerBaseAddress[ConfigPtr->Channel];

	CLR_BIT(Pwm->GPTMCTL , 0 );                  /*disable timer*/

	Pwm->GPTMCFG = 0x00000004;                 /*No Concatanation */
	
	Pwm->GPTMIMR = 0x0000;                    /* disable all interrupts*/

	SET_BIT (Pwm->GPTMTAMR , 3);              /*PWM MODE*/

	CLR_BIT (Pwm->GPTMTAMR , 2);		    /*No INPUT CAPTURE*/

	SET_BIT (Pwm->GPTMTAMR , 1);	          /*periodoc*/

	SET_BIT (Pwm->GPTMTAMR , 0);		   /*periodic*/
	
	CLR_BIT(Pwm->GPTMCTL , 6);			   /*non inverting*/

	Pwm->GPTMTAPR = ConfigPtr->PwmChannelTickFrequency ;  /* set prescaler */

}

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Start Timer Count 
*	\sync\Async      :	ASynchronous
*	\Reentrancy      : non_Reentrant
*	\Parameters (in) :	Pwm_ChannelType Channel	"Timer ID " , Gpt_ValueType Value "No.of Counts in Tick"
*	\Parameters (out):	void
*************************************************************************************************************************/

void Pwm_StartTimer(Pwm_ChannelType Channel , Pwm_ValueType Value , Pwm_ValueType MatchValue){

	volatile Gpt_RegsType*Pwm= (volatile Gpt_RegsType*)Pwm_TimerBaseAddress[Channel];

	volatile uint32 Pwm_Offset = (Pwm_TimerBaseAddress[Channel]-0x40000000);


	Pwm->GPTMTAILR= Value;		
	
	Pwm->GPTMTAMATCHR= MatchValue;
	
	(BIT_BANDING(Pwm_Offset , 0x00C , 0))=1;                     /*SET_BIT( Pwm->GPTMCTL ,0).......Start timer.*/
}


/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Set Match Value Timer Count according to desired Duty cycle "recieve No. of ticks from user" 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Pwm_ChannelType :Channel	"Timer ID " & Pwm_ValueType: Match value 
*	\Parameters (out):	void
*************************************************************************************************************************/


void Pwm_SetMatchValue(Pwm_ChannelType Channel , Pwm_ValueType MatchValue){

		volatile Gpt_RegsType*Pwm= (volatile Gpt_RegsType*)Pwm_TimerBaseAddress[Channel];

		Pwm->GPTMTAMATCHR= MatchValue;

	
}


/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Stop Timer Count 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Pwm_ChannelType Channel	"Timer ID " 
*	\Parameters (out):	void
*************************************************************************************************************************/


void Pwm_StopTimer(Pwm_ChannelType Channel){

	volatile Gpt_RegsType*Pwm= (volatile Gpt_RegsType*)Pwm_TimerBaseAddress[Channel];

	volatile uint32 Pwm_Offset = (Pwm_TimerBaseAddress[Channel]-0x40000000);

	((BIT_BANDING(Pwm_Offset , 0x00C , 0)))= 0;           /*CLR_BIT( Gpt->GPTMCTL ,0)........stop timer.*/

	Pwm->GPTMTAILR=0;

	Pwm->GPTMTAMATCHR=0;
}



/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Disable pwm-Timer Interrupts in Run Time 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	Pwm_ChannelType Channel	"Timer ID "
*	\Parameters (out):	void
*************************************************************************************************************************/

void Pwm_DisableNotification(Pwm_ChannelType Channel){

	volatile Pwm_RegsType*Pwm= (volatile Pwm_RegsType*)Pwm_TimerBaseAddress[Channel];

	volatile uint32 Pwm_Offset = (Pwm_TimerBaseAddress[Channel]-0x40000000);
	
	((BIT_BANDING(Pwm_Offset , 0x00C , 0)))= 0;           /*CLR_BIT( Gpt->GPTMCTL ,0)........stop timer.*/

	((BIT_BANDING(Pwm_Offset , 0x004 , 9)))= 1;           /*CLR_BIT( Gpt->GPTMAMR ,9)........disable Pwm Interrupt.*/

	((BIT_BANDING(Pwm_Offset , 0x00C , 0)))= 1;           /*CLR_BIT( Gpt->GPTMCTL ,0)........start timer.*/

}

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Enable Timer Interrupts in Run Time 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	Pwm_ChannelType Channel	"Timer ID "
*	\Parameters (out):	void
*************************************************************************************************************************/

void Pwm_EnableNotification(Pwm_ChannelType Channel){

	volatile Pwm_RegsType*Pwm= (volatile Pwm_RegsType*)Pwm_TimerBaseAddress[Channel];

	volatile uint32 Pwm_Offset = (Pwm_TimerBaseAddress[Channel]-0x40000000);

	((BIT_BANDING(Pwm_Offset , 0x00C , 0)))= 0;           /*CLR_BIT( Gpt->GPTMCTL ,0)........stop timer.*/

	((BIT_BANDING(Pwm_Offset , 0x00C , 2)))= 0;           /*CLR_BIT( Gpt->GPTMCTL ,2)........edge detect interrrupt positive edge*/

	((BIT_BANDING(Pwm_Offset , 0x00C , 3)))= 0;           /*CLR_BIT( Gpt->GPTMCTL ,2)........edge detect interrrupt positive edge*/

	((BIT_BANDING(Pwm_Offset , 0x004 , 9)))= 1;           /*CLR_BIT( Gpt->GPTMAMR ,9)........enable Pwm Interrupt.*/

	((BIT_BANDING(Pwm_Offset , 0x00C , 0)))= 1;           /*CLR_BIT( Gpt->GPTMCTL ,0)........start timer.*/

}
