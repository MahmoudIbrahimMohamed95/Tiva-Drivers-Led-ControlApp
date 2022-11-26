#ifndef EXTI_H_
#define EXTI_H_


/**********************************************************************************************************************************************

* GLOBAL VARIABLES AND MACROS

**********************************************************************************************************************************************/

static volatile void(*Exti_CallBack[6])(void)={NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR};


/****************************************************************************************************************************
*	GLOBAL DATA TYPES AND STRUCTURES
****************************************************************************************************************************/


typedef  void(*Exti_NotificationType)(void);

typedef enum{

    EXTI_PA0 , EXTI_PA1 , EXTI_PA2 ,EXTI_PA3 , EXTI_PA4 , EXTI_PA5 ,EXTI_PA6 , EXTI_PA7 ,
    EXTI_PB0,EXTI_PB1,EXTI_PB2,EXTI_PB3,EXTI_PB4,EXTI_PB5,EXTI_PB6,EXTI_PB7,
    EXTI_PC0,EXTI_PC1,EXTI_PC2,EXTI_PC3,EXTI_PC4,EXTI_PC5,EXTI_PC6,EXTI_PC7,
    EXTI_PD0,EXTI_PD1,EXTI_PD2,EXTI_PD3,EXTI_PD4,EXTI_PD5,EXTI_PD6,EXTI_PD7,
    EXTI_PE0,EXTI_PE1,EXTI_PE2,EXTI_PE3,EXTI_PE4,EXTI_PE5,
    EXTI_PF0,EXTI_PF1,EXTI_PF2,EXTI_PF3,EXTI_PF4,

}Exti_ChannelType;

typedef enum{

    EXTI_RAISING_EDGE , EXTI_FALLING_EDGE , EXTI_ON_CHANGE , EXTI_HIGH_LEVEl , EXTI_LOW_LEVEL 

}Exti_LevelType;


typedef struct{

    Exti_ChannelType        Exti_Channel;
    Exti_LevelType          Exti_Level;
    Exti_NotificationType   Exti_Notification;

}Exti_ConfigType;


/****************************************************************************************************************************
*	GLOBAL FUNCTION PROTOTYPES
****************************************************************************************************************************/



/****************************************************************************************************************************
*	\syntax          :	void Exti_Init(const Exti_ConfigType* ConfigPtr)
*	\Description     :  function to set External Interrupts Configurations 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	const Exti_ConfigType*ConfigPtr "Pointer to struct"
*	\Parameters (out):	void
*************************************************************************************************************************/
 
void Exti_Init(const Exti_ConfigType* ConfigPtr);


/****************************************************************************************************************************
*	\syntax          :	void Exti_EnableInterrupt(Exti_ChannelType Channel)
*	\Description     :  function to enable External Interrupt. 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Exti_ChannelType Channel
*	\Parameters (out):	void
*************************************************************************************************************************/
 

void Exti_EnableInterrupt(Exti_ChannelType Channel);


/****************************************************************************************************************************
*	\syntax          :	void Exti_DisableInterrupt(Exti_ChannelType Channel)
*	\Description     :  function to disable External Interrupt. 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Exti_ChannelType Channel
*	\Parameters (out):	void
*************************************************************************************************************************/
 

void Exti_DisableInterrupt(Exti_ChannelType Channel);


#endif