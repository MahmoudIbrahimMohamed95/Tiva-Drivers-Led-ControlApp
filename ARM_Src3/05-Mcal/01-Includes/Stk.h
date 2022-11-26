/*****************************************************************************************************************************
*FILE DESCRIPTION
*-----------------------------------------------------------------------------------------------------------------------------
*   FILE: Stk.h

*	Module:   STK_H_

*   DESCRIPTION: header file for Core Periphral SystemTick interface "Systick"

*
*****************************************************************************************************************************/


/****************************************************************************************************************************

* INCLUDES:

*****************************************************************************************************************************/


#ifndef STK_H_
#define STK_H_



/**********************************************************************************************************************************************

* GLOBAL VARIABLES AND MACROS

**********************************************************************************************************************************************/

static volatile void (*Stk_CallBackPtr)(void) = NULL_PTR;


/****************************************************************************************************************************
*	GLOBAL DATA TYPES AND STRUCTURES
****************************************************************************************************************************/


typedef enum{

    STK_INT_EN , STK_INT_DIS
}Stk_IntType;

typedef enum{

    STK_PIOSC_DIV4 , STK_SYSTEM_CLOCK
}Stk_ClockType;

typedef  uint32  Stk_ValueType;

typedef  void(*Stk_NotificationType)(void);

typedef struct{

Stk_IntType       Stk_Int;

Stk_ClockType     Stk_Clock;

Stk_NotificationType  Stk_Notification;    

}Stk_ConfigType;




/****************************************************************************************************************************
*	GLOBAL FUNCTION PROTOTYPES
****************************************************************************************************************************/



/****************************************************************************************************************************
*	\syntax          :	void Stk_IntCtrlInit (const Stk_ConfigType* ConfigPtr  );  
*	\Description     :  function to Intialize systick Configurations 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	const Stk_ConfigType*ConfigPtr "Pointer to struct"
*	\Parameters (out):	void
*************************************************************************************************************************/

void Stk_Init(const Stk_ConfigType* ConfigPtr);

/****************************************************************************************************************************
*	\syntax          :	void Stk_SetBusyWait  
*	\Description     :  function to generate blocking delay
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	(Stk_ValueType Stk_Value)
*	\Parameters (out):	void
*************************************************************************************************************************/

void Stk_SetBusyWait(Stk_ValueType Stk_Value);


/****************************************************************************************************************************
*	\syntax          :	void Stk_SetIntervalPeriodic  
*	\Description     :  function to Set the Timer Value and make it work Periodic
*	\sync\Async      :	ASynchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	(Stk_ValueType Stk_Value)
*	\Parameters (out):	void
*************************************************************************************************************************/



void Stk_SetIntervalPeriodic(Stk_ValueType Stk_Value);


/****************************************************************************************************************************
*	\syntax          :	void Stk_SetIntervalPeriodic  
*	\Description     :  function to Start Timer
*	\sync\Async      :	ASynchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	(Stk_ValueType Stk_Value)
*	\Parameters (out):	void
*************************************************************************************************************************/



void Stk_StartTimer(Stk_ValueType Stk_Value);


/****************************************************************************************************************************
*	\syntax          :	void Stk_StopTimer  
*	\Description     :  function to Stop the Timer 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	(Stk_ValueType Stk_Value)
*	\Parameters (out):	void
*************************************************************************************************************************/

void Stk_StopTimer(void);



/****************************************************************************************************************************
*	\syntax          :	Stk_ValueType Stk_GetTimeElapsed(void) 
*	\Description     :  function to Get time passed from the starting of Count. 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	void
*	\Parameters (out):	Stk_ValueType
*************************************************************************************************************************/

Stk_ValueType Stk_GetTimeElapsed(void);

/****************************************************************************************************************************
*	\syntax          :	Stk_ValueType Stk_GetTimeRemaining(void) 
*	\Description     :  function to Get time remaining from the starting of Count. 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	void
*	\Parameters (out):	Stk_ValueType
*************************************************************************************************************************/

Stk_ValueType Stk_GetTimeRemaining(void);



void SysTick_Handler(void);
#endif