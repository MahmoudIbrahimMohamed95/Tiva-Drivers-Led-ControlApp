/*****************************************************************************************************************************
*FILE DESCRIPTION
*-----------------------------------------------------------------------------------------------------------------------------
*		FILE: Gpt.h

*	Module:   GPT_H_

*DESCRIPTION: header file for General Purpose timer Periphral interface

*
*****************************************************************************************************************************/


#ifndef NVIC_H_

#define NVIC_H_

/****************************************************************************************************************************
*	GLOBAL DATA TYPES AND STRUCTURES
****************************************************************************************************************************/


typedef enum {

      GPIOA_Handler_Indix  , GPIOB_Handler_Indix  , GPIOC_Handler_Indix , GPIOD_Handler_Indix , GPIOE_Handler_Indix    ,UART0_Handler_Indix             

    ,UART1_Handler_Indix   ,SSI0_Handler_Indix ,I2C0_Handler_Indix   , PMW0_FAULT_Handler_Indix , PWM0_0_Handler_Indix            

    ,PWM0_1_Handler_Indix  , PWM0_2_Handler_Indix , QEI0_Handler_Indix  ,ADC0SS0_Handler_Indix     ,ADC0SS1_Handler_Indix           

    ,ADC0SS2_Handler_Indix ,ADC0SS3_Handler_Indix ,WDT0_Handler_Indix   ,TIMER0A_Handler_Indix     ,TIMER0B_Handler_Indix         

    ,TIMER1A_Handler_Indix ,TIMER1B_Handler_Indix ,TIMER2A_Handler_Indix ,TIMER2B_Handler_Indix    ,ANALOG_COMPARATOR_Handler_Indix     ,ANALOG_COMPARATOR1_Handler_Indix             

    ,RESERVEDD   ,SYSTEM_CTL_Handler_Indix  ,FLASH_Handler_Indix   ,GPIOF_Handler_Indix      ,RESRERVEDDD      ,RESERVEDDDD             

    ,UART2_Handler_Indix   ,SSI1_Handler_Indix    ,TIMER3A_Handler_Indix ,TIMER3B_Handler_Indix    ,I2C1_Handler_Indix       ,QEI1_Handler_Indix              

    ,CAN0_Handler_Indix    ,CAN1_Handler_Indix    , RRESERVED   ,RESERVED0 ,HIB_Handler_Indix     ,USB_Handler_Indix       ,PWM0_GENERATOR_3_Handler_Indix            

    ,UDMA_Handler_Indix    ,UDMAERROR_Handler_Indix ,ADC1SS0_Handler_Indix ,ADC1SS1_Handler_Indix    ,ADC1SS2_Handler_Indix    ,ADC1SS3_Handler_Indix 

    ,   RESERVED1            ,RESERVED2    ,RRRESERVED   ,RRRRESERVED      ,RRRRESERVEDD      ,SSI2_Handler_Indix              

    ,SSI3_Handler_Indix    ,UART3_Handler_Indix   ,UART4_Handler_Indix   ,UART5_Handler_Indix      ,UART6_Handler_Indix      ,UART7_Handler_Indix             

    ,RESERVED3        ,RESERVED4     , RESERVED5         ,RESERVED6    ,I2C2_Handler_Indix       ,I2C3_Handler_Indix             

    ,TIMER4A_Handler_Indix ,TIMER4B_Handler_Indix ,RESERVED7        ,RESERVED8        ,RESERVED9        ,RESERVED10                       

    ,    RESERVED11  ,RESERVED12       ,  RESERVED13    ,    RESERVED14        ,     RESERVED15        ,RESERVED16                        

    ,      RESERVED17  ,  RESERVED18        ,RESERVED19    ,RESERVED20       ,RESERVED21    ,RESERVED22  

    ,  RESERVED23    ,   RESERVED24    ,  RESERVED25    ,   RESERVED26      ,TIMER5A_Handler_Indix    ,TIMER5B_Handler_Indix           

    ,WTIMER0A_Handler_Indix ,WTIMER0B_Handler_Indix         ,WTIMER1A_Handler_Indix          ,WTIMER1B_Handler_Indix   ,WTIMER2A_Handler_Indix 

    , WTIMER2B_Handler_Indix  , WTIMER3A_Handler_Indix      ,WTIMER3B_Handler_Indix        ,WTIMER4A_Handler_Indix    ,WTIMER4B_Handler_Indix       

    ,WTIMER5A_Handler_Indix   , WTIMER5B_Handler_Indix      ,SYSEXCEPTION_Handler_Indix       ,RESERVED27       ,     RESERVED28                         

    ,RESERVED29    ,RESERVED30     ,RESERVED31    ,RESERVED32    , RESERVED33             

    ,RESERVED34          ,  RESERVED35       ,RESERVED36 ,RESERVED37    ,RESERVED38            

    ,RESERVED39    ,GPIOP4_Handler_Indix          ,GPIOP5_Handler_Indix        ,GPIOP6_Handler_Indix     ,GPIOP7_Handler_Indix           

    ,GPIOQ0_Handler_Indix ,GPIOQ1_Handler_Indix, GPIOQ2_Handler_Indix ,GPIOQ3_Handler_Indix   ,GPIOQ4_Handler_Indix           

    ,GPIOQ5_Handler_Indix,GPIOQ6_Handler_Indix       ,GPIOQ7_Handler_Indix        , GPIOR_Handler_Indix        ,GPIOS_Handler_Indix             

    ,PMW1_GENERATOR0_Handler_Indix     ,PWM1_GENERATOR1_Handler_Indix          ,PWM1_GENERATOR2_Handler_Indix        ,PWM1_GENERATOR3_Handler_Indix        ,PWM1_FAULT_Handler_Indix        

}IntCtrl_InterruptType;


typedef   uint8   PeriorityType;


typedef struct {

IntCtrl_InterruptType     IntCtrl_Interrupt;

PeriorityType             Periority;


}Nvic_ConfigType;


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


void Nvic_IntCtrlInit (const Nvic_ConfigType* ConfigPtr  );   /*Function To Set Software Priority  */


/****************************************************************************************************************************
*	\syntax          :	void Nvic_IntEnable (IntCtrl_InterruptType InterruptType) 
*	\Description     :  function to Enable  Interrupts 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	IntCtrl_InterruptType InterruptType
*	\Parameters (out):	void
*************************************************************************************************************************/



void Nvic_IntEnable (IntCtrl_InterruptType InterruptType);    /*Function to Enable interrupt */


/****************************************************************************************************************************
*	\syntax          :	void Nvic_IntDisable (IntCtrl_InterruptType InterruptType) 
*	\Description     :  function to Disable  Interrupts 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	IntCtrl_InterruptType InterruptType
*	\Parameters (out):	void
*************************************************************************************************************************/


void Nvic_IntDisable (IntCtrl_InterruptType InterruptType);   /*Function to Disable interrupt */



/****************************************************************************************************************************
*	\syntax          :	void Nvic_SetPendingFlag (IntCtrl_InterruptType InterruptType) 
*	\Description     :  function to Set Pending Flags of Interrupts 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	IntCtrl_InterruptType InterruptType
*	\Parameters (out):	void
*************************************************************************************************************************/


void Nvic_SetPendingFlag (IntCtrl_InterruptType InterruptType);   /*Function to Set Pending */


/****************************************************************************************************************************
*	\syntax          :	void Nvic_ClearPendingFlag (IntCtrl_InterruptType InterruptType) 
*	\Description     :  function to Clear Pending Flag of Interrupts 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	IntCtrl_InterruptType InterruptType
*	\Parameters (out):	void
*************************************************************************************************************************/



void Nvic_ClearPendingFlag (IntCtrl_InterruptType InterruptType); /*Function to Clear Pending */



/****************************************************************************************************************************
*	\syntax          :	void Nvic_TriggerSwInt (IntCtrl_InterruptType InterruptType) 
*	\Description     :  function to Trigger Software Interrupts 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	IntCtrl_InterruptType InterruptType
*	\Parameters (out):	void
*************************************************************************************************************************/


void Nvic_TriggerSwInt (IntCtrl_InterruptType InterruptType); /*Function to trigger intrepput*/

#endif