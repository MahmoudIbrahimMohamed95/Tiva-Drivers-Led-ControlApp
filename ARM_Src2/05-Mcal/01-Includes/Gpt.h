/*****************************************************************************************************************************
*FILE DESCRIPTION
*-----------------------------------------------------------------------------------------------------------------------------
*		FILE: Gpt.h

*	Module:   GPT_H_

*DESCRIPTION: header file for General Purpose timer Periphral interface

*
*****************************************************************************************************************************/


#ifndef GPT_H_
#define GPT_H_
/**********************************************************************************************************************************************

* GLOBAL VARIABLES AND MACROS

**********************************************************************************************************************************************/

static volatile void (*Gpt_callBackPtr[12])(void) = {NULL_PTR , NULL_PTR , NULL_PTR , NULL_PTR , NULL_PTR , NULL_PTR , NULL_PTR , NULL_PTR 

, NULL_PTR , NULL_PTR , NULL_PTR , NULL_PTR};

static volatile uint32 Gpt_ChannelMaxTick[12]={0};


/****************************************************************************************************************************
*	GLOBAL DATA TYPES AND STRUCTURES
****************************************************************************************************************************/

typedef enum{

	TIMER0_16_32 ,TIMER1_16_32 ,TIMER2_16_32 ,TIMER3_16_32 ,TIMER4_16_32 ,TIMER5_16_32

	,TIMER0_32_64 ,TIMER1_32_64 ,TIMER2_32_64 ,TIMER3_32_64 ,TIMER4_32_64 ,TIMER5_32_64

}Gpt_ChannelType;

typedef enum{

	GPT_PREDEF_TIMER_100US_32BIT , GPT_PREDEF_TIMER_1US_16BIT , GPT_PREDEF_TIMER_1US_24BIT , GPT_PREDEF_TIMER_1US_32BIT    

}Gpt_PredefTimerType;

typedef enum{

	ONE_SHOOT , PERIODIC

}Gpt_ModeType;



typedef uint32  Gpt_ValueType;



typedef  void(*Gpt_NotificationType)(void);

typedef struct{

Gpt_ChannelType  Channel;

Gpt_ValueType	      GptChannelTickFrequency;  /*Prescaler*/

Gpt_ValueType         GptChannelTickValueMax;  /*note that this is max value in bits position ex:0b1111*/

Gpt_ModeType	      GptChannelMode;

Gpt_NotificationType  Gpt_Notification;


}Gpt_ConfigType;


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

void Gpt_Init(const Gpt_ConfigType*ConfigPtr);


/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Disable Timer Interrupts in Run Time 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	Gpt_ChannelType Channel	"Timer ID "
*	\Parameters (out):	void
*************************************************************************************************************************/
void Gpt_DisableNotification(Gpt_ChannelType Channel);


/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Enable Timer Interrupts in Run Time 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	Gpt_ChannelType Channel	"Timer ID "
*	\Parameters (out):	void
*************************************************************************************************************************/
void Gpt_EnableNotification(Gpt_ChannelType Channel);



/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Start Timer Count 
*	\sync\Async      :	ASynchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Gpt_ChannelType Channel	"Timer ID " , Gpt_ValueType Value "No.of Counts in Tick"
*	\Parameters (out):	void
*************************************************************************************************************************/
void Gpt_StartTimer(Gpt_ChannelType Channel , Gpt_ValueType Value);



/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Stop Timer Count 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Gpt_ChannelType Channel	"Timer ID " 
*	\Parameters (out):	void
*************************************************************************************************************************/
void Gpt_StopTimer(Gpt_ChannelType Channel);



/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Get Time Elapsed from Begaining of Count  
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Gpt_ChannelType Channel	"Timer ID " 
*	\Parameters (out):	Gpt_ValueType  "uint 32"
*************************************************************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);



/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to get Remaining Time 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Gpt_ChannelType Channel	"Timer ID "  
*	\Parameters (out):	Gpt_ValueType Value "No.of Counts in Tick"
*************************************************************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);



/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Initialize the Predefined Timers which is defined before Run Time 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	Gpt_PredefTimerType PredefTimer "fixed Timer ID which is Timer0_32_64 "  
*	\Parameters (out):	void
*************************************************************************************************************************/
void Gpt_PredefTimerInit(Gpt_PredefTimerType PredefTimer);



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

Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer , uint32*TimeValuePtr);


#endif

/***************************************************************************************************************************
*	END OF FILE :GPT_H_
***************************************************************************************************************************/
