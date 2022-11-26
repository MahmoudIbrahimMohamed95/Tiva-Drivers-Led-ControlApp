/*****************************************************************************************************************************
*FILE DESCRIPTION
*-----------------------------------------------------------------------------------------------------------------------------
*   FILE: Nvic.c

*	Module:   NVIC_C_

*   DESCRIPTION: source file for Core Periphral Interrupt interface "Nvic"

*
*****************************************************************************************************************************/


/****************************************************************************************************************************

* INCLUDES:

*****************************************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Nvic.h"
#include "Nvic_Private.h"




/****************************************************************************************************************************
*	GLOBAL FUNCTION PROTOTYPES
****************************************************************************************************************************/



/****************************************************************************************************************************
*	\syntax          :	void Nvic_IntCtrlInit (const Nvic_ConfigType* ConfigPtr  );  
*	\Description     :  function to set Software Pariority of Interrupts 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	const Nvic_ConfigType*ConfigPtr "Pointer to struct"
*	\Parameters (out):	void
*************************************************************************************************************************/

void Nvic_IntCtrlInit(const Nvic_ConfigType* ConfigPtr){

    uint32 priority_Indix= (ConfigPtr->IntCtrl_Interrupt) / 4;

    uint32 priority_Shifting= (ConfigPtr->IntCtrl_Interrupt) % 4;

    NVIC_PRI[priority_Indix] =  ((ConfigPtr->Periority)<<((priority_Shifting * 8)+5)); 
		

}


/****************************************************************************************************************************
*	\syntax          :	void Nvic_IntEnable (IntCtrl_InterruptType InterruptType) 
*	\Description     :  function to Enable  Interrupts 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	IntCtrl_InterruptType InterruptType
*	\Parameters (out):	void
*************************************************************************************************************************/


void Nvic_IntEnable (IntCtrl_InterruptType InterruptType){

    if(InterruptType<=31){

        SET_BIT( NVIC_EN0 ,InterruptType);

    }
    else if(InterruptType <= 63){

    
        SET_BIT( NVIC_EN1 ,(InterruptType-32));    

    }
    else if(InterruptType <= 95){

        SET_BIT( NVIC_EN2 ,(InterruptType-64));

    }
		else if(InterruptType <= 127){

        SET_BIT( NVIC_EN3 ,(InterruptType-96));

    }
    else{

        ;

        }
}


/****************************************************************************************************************************
*	\syntax          :	void Nvic_IntDisable (IntCtrl_InterruptType InterruptType) 
*	\Description     :  function to Disable  Interrupts 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	IntCtrl_InterruptType InterruptType
*	\Parameters (out):	void
*************************************************************************************************************************/


void Nvic_IntDisable (IntCtrl_InterruptType InterruptType){

    
    if(InterruptType<=31){

        SET_BIT( NVIC_DIS0 ,InterruptType);

    }
    else if(InterruptType <= 63){

    
        SET_BIT( NVIC_DIS1 ,(InterruptType-32));    

    }
    else if(InterruptType <= 95){

        SET_BIT( NVIC_DIS2 ,(InterruptType-64));

    }
		else if(InterruptType <= 127){

        SET_BIT( NVIC_DIS3 ,(InterruptType-96));

    }
    else{

        ;

        }

}

/****************************************************************************************************************************
*	\syntax          :	void Nvic_SetPendingFlag (IntCtrl_InterruptType InterruptType) 
*	\Description     :  function to Set Pending Flags of Interrupts 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	IntCtrl_InterruptType InterruptType
*	\Parameters (out):	void
*************************************************************************************************************************/


void Nvic_SetPendingFlag (IntCtrl_InterruptType InterruptType){

    
    if(InterruptType<=31){

        SET_BIT( NVIC_PEND0 ,InterruptType);

    }
    else if(InterruptType <= 63){

    
        SET_BIT( NVIC_PEND1 ,(InterruptType-32));    

    }
    else if(InterruptType <= 95){

        SET_BIT( NVIC_PEND2 ,(InterruptType-64));

    }
    else{

        ;

        }


}


/****************************************************************************************************************************
*	\syntax          :	void Nvic_ClearPendingFlag (IntCtrl_InterruptType InterruptType) 
*	\Description     :  function to Clear Pending Flag of Interrupts 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	IntCtrl_InterruptType InterruptType
*	\Parameters (out):	void
*************************************************************************************************************************/


void Nvic_ClearPendingFlag (IntCtrl_InterruptType InterruptType){

    
    if(InterruptType<=31){

        SET_BIT( NVIC_UNPEND0 ,InterruptType);

    }
    else if(InterruptType <= 63){

    
        SET_BIT( NVIC_UNPEND1 ,(InterruptType-32));    

    }
    else if(InterruptType <= 95){

        SET_BIT( NVIC_UNPEND2 ,(InterruptType-64));

    }
    else{

        ;

        }
        
}


/****************************************************************************************************************************
*	\syntax          :	void Nvic_TriggerSwInt (IntCtrl_InterruptType InterruptType) 
*	\Description     :  function to Trigger Software Interrupts 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	IntCtrl_InterruptType InterruptType
*	\Parameters (out):	void
*************************************************************************************************************************/

void Nvic_TriggerSwInt (IntCtrl_InterruptType InterruptType){


    NVIC_SWTRIG= InterruptType;

}