/*****************************************************************************************************************************
*FILE DESCRIPTION
*-----------------------------------------------------------------------------------------------------------------------------
*		FILE: Pwm.h

*	Module:   PWM_H_

*DESCRIPTION: header file for PWM timer Periphral interface

*
*****************************************************************************************************************************/

#ifndef PWM_H_
#define PWM_H_


/****************************************************************************************************************************
*	GLOBAL DATA TYPES AND STRUCTURES
****************************************************************************************************************************/

typedef enum{

     PWM_TIMER0_16_32 ,PWM_TIMER1_16_32 ,PWM_TIMER2_16_32 ,PWM_TIMER3_16_32 ,PWM_TIMER4_16_32 ,PWM_TIMER5_16_32

	,PWM_TIMER0_32_64 ,PWM_TIMER1_32_64 ,PWM_TIMER2_32_64 ,PWM_TIMER3_32_64 ,PWM_TIMER4_32_64 ,PWM_TIMER5_32_64

}Pwm_ChannelType;


typedef uint32   Pwm_ValueType;
typedef uint32   Pwm_RegsType;

typedef  void(*Pwm_NotificationType)(void);



typedef struct{

Pwm_ChannelType           Channel;

Pwm_ValueType	          PwmChannelTickFrequency;   /*Prescaler*/

Pwm_NotificationType      Pwm_Notification;

}Pwm_ConfigType;

/****************************************************************************************************************************
*	GLOBAL FUNCTION PROTOTYPES
****************************************************************************************************************************/


/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to set Pwm-Timer Configurations 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	const Pwm_ConfigType*ConfigPtr "Pointer to struct"
*	\Parameters (out):	void
*************************************************************************************************************************/

void Pwm_Init(const Pwm_ConfigType*ConfigPtr);

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Disable pwm-Timer Interrupts in Run Time 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	Pwm_ChannelType Channel	"Timer ID "
*	\Parameters (out):	void
*************************************************************************************************************************/

void Pwm_DisableNotification(Pwm_ChannelType Channel);

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Enable Timer Interrupts in Run Time 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	Pwm_ChannelType Channel	"Timer ID "
*	\Parameters (out):	void
*************************************************************************************************************************/

void Pwm_EnableNotification(Pwm_ChannelType Channel);

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Set Match Value Timer Count according to desired Duty cycle "recieve No. of ticks from user" 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Pwm_ChannelType :Channel	"Timer ID " & Pwm_ValueType: Match value 
*	\Parameters (out):	void
*************************************************************************************************************************/


void Pwm_SetMatchValue(Pwm_ChannelType Channel , Pwm_ValueType MatchValue);


/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Start Timer Count 
*	\sync\Async      :	ASynchronous
*	\Reentrancy      : non_Reentrant
*	\Parameters (in) :	Pwm_ChannelType Channel	"Timer ID " , Gpt_ValueType Value "No.of Counts in Tick"
*	\Parameters (out):	void
*************************************************************************************************************************/
void Pwm_StartTimer(Pwm_ChannelType Channel , Pwm_ValueType Value ,Pwm_ValueType MatchValue);


/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to Stop Timer Count 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Pwm_ChannelType Channel	"Timer ID " 
*	\Parameters (out):	void
*************************************************************************************************************************/
void Pwm_StopTimer(Pwm_ChannelType Channel);


#endif