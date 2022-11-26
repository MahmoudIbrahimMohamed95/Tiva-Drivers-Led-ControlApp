/*****************************************************************************************************************************
*FILE DESCRIPTION
*-----------------------------------------------------------------------------------------------------------------------------
*   FILE: Stk.c

*	Module:   STK_C_

*   DESCRIPTION: source file for Core Periphral SystemTick interface "Systick"

*
*****************************************************************************************************************************/


/****************************************************************************************************************************

* INCLUDES:

*****************************************************************************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Stk.h"
#include "Stk_Private.h"



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


void Stk_Init(const Stk_ConfigType* ConfigPtr){

    switch (ConfigPtr->Stk_Int){
 
        case STK_INT_EN:   
           SET_BIT (STK_STCTRL , 1); break;
 
        case STK_INT_DIS: 
           CLR_BIT( STK_STCTRL , 1); break;
 
        default: break;  
    }
    switch (ConfigPtr->Stk_Clock){
 
        case STK_PIOSC_DIV4 :   
  
           CLR_BIT (STK_STCTRL , 2); break;
 
        case STK_SYSTEM_CLOCK: 
  
           SET_BIT(STK_STCTRL , 2); break;
 
        default: break;  
    }
 
    Stk_CallBackPtr= ConfigPtr->Stk_Notification;

}

/****************************************************************************************************************************
*	\syntax          :	void Stk_SetBusyWait  
*	\Description     :  function to generate blocking delay
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	(Stk_ValueType Stk_Value)
*	\Parameters (out):	void
*************************************************************************************************************************/


void Stk_SetBusyWait(Stk_ValueType Stk_Value){     

    STK_STRELOAD= Stk_Value;

		SET_BIT(STK_STCTRL , 0);

		while((GET_BIT(STK_STCTRL , 16))==0){
			continue;
		}

        CLR_BIT(STK_STCTRL , 0);

        STK_STRELOAD= 0;

        STK_STCURRENT=0;
}


/****************************************************************************************************************************
*	\syntax          :	void Stk_SetIntervalPeriodic  
*	\Description     :  function to Set the Timer Value and make it work Periodic
*	\sync\Async      :	ASynchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	(Stk_ValueType Stk_Value)
*	\Parameters (out):	void
*************************************************************************************************************************/

void Stk_SetIntervalPeriodic(Stk_ValueType Stk_Value){

        SET_BIT(STK_STCTRL , 0);

        STK_STRELOAD= Stk_Value;

}

/****************************************************************************************************************************
*	\syntax          :	void Stk_StopTimer  
*	\Description     :  function to Stop the Timer 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	(Stk_ValueType Stk_Value)
*	\Parameters (out):	void
*************************************************************************************************************************/


void Stk_StopTimer(void){

    CLR_BIT(STK_STCTRL , 0);

        STK_STRELOAD= 0;

        STK_STCURRENT=0;
}


/****************************************************************************************************************************
*	\syntax          :	Stk_ValueType Stk_GetTimeElapsed(void) 
*	\Description     :  function to Get time passed from the starting of Count. 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	void
*	\Parameters (out):	Stk_ValueType
*************************************************************************************************************************/


Stk_ValueType Stk_GetTimeElapsed(void){

    return (STK_STRELOAD - STK_STCURRENT );
}
/****************************************************************************************************************************
*	\syntax          :	Stk_ValueType Stk_GetTimeRemaining(void) 
*	\Description     :  function to Get time remaining from the starting of Count. 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	void
*	\Parameters (out):	Stk_ValueType
*************************************************************************************************************************/


Stk_ValueType Stk_GetTimeRemaining(void){

    return STK_STCURRENT;
}


/****************************************************************************************************************************
*	\syntax          :	SysTick_Handler 
*	\Description     :  Systick ISr's Handler 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Based On Interrupt Nesting (Enable /Not Enable)
*	\Parameters (in) :	void
*	\Parameters (out):	void
*************************************************************************************************************************/


void SysTick_Handler(void){

    if(Stk_CallBackPtr != NULL_PTR){

         Stk_CallBackPtr();   

    }
}