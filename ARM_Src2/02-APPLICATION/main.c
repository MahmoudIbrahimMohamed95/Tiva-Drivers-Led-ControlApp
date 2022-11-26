/*****************************************************************************************************************************
*FILE DESCRIPTION
*-----------------------------------------------------------------------------------------------------------------------------
*   FILE: main.c

*		Module:   APPLICATION_C_

*   DESCRIPTION: source file for APPLICATION Implementation

*
*****************************************************************************************************************************/


/****************************************************************************************************************************

*  INCLUDES-:

*****************************************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mcu.h"
#include "Stk.h"
#include "Nvic.h"
#include "Gpio_Dio.h"
#include "Gpio_Port.h"
#include "Pwm.h"
#include "Exti.h"


/**********************************************************************************************************************************************

* GLOBAL VARIABLES AND MACROS

**********************************************************************************************************************************************/
	
volatile  uint8 TURN_ON_TIME =5;

volatile  uint8 TURN_OFF_TIME=5;
volatile static uint8 Sw1_gVariable=0;
volatile static uint8 Sw2_gVariable=0;

/**********************************************************************************************************************************************

* FUNCTION PROTOTYPE

**********************************************************************************************************************************************/


void SW1_Processing (void);
void SW2_Processing (void);

/** Function to process Switch_1 ISR **/

void SW1_Processing (void){
	
	Sw1_gVariable=1;
}

/** Function to process Switch_2 ISR **/

void SW2_Processing (void){

	Sw2_gVariable=1;

}

int main(void){

Mcu_ConfigType  Mcu_Config[4] ={{MOSC ,MCU_PORTA },{MOSC ,MCU_PORTB },{MOSC ,MCU_PORTF } , {MOSC , MCU_TIMER1 }};
Stk_ConfigType  Stk_Config = {STK_INT_DIS , STK_SYSTEM_CLOCK , NULL_PTR};
Pwm_ConfigType  Pwm_Config = {PWM_TIMER1_16_32 , 0x00 , NULL_PTR};
Port_ConfigType Port_Config[4] = {{PPF3 , OUTPUT , PWM , PULL_DOWN , FOUR_mA},{PPA0 , INPUT , DIO , PULL_DOWN , FOUR_mA},{PPB0 , INPUT , DIO , PULL_DOWN , FOUR_mA},{PPA2 , OUTPUT , DIO , FLOATING , FOUR_mA}};	
Exti_ConfigType	Exti_Config[2]={{EXTI_PA0 ,EXTI_RAISING_EDGE ,SW1_Processing },{EXTI_PB0 , EXTI_RAISING_EDGE ,SW2_Processing}};	

uint16 i=0;


	for(i=0 ;i<4 ; i++){

		Mcu_Init(&Mcu_Config[i]);

	}
	

/****************************************************************************************************************************
*	\syntax     		  : void Port_Init(const Port_ConfigType* ConfigPtr )
*	\Description     :  function to set configuration for all GPIO of Mcu and it's Alternative Functions 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	pointer to Struct of Configurations
*	\Parameters (out):	void
*	\Return value	 :	void
*************************************************************************************************************************/

	for(i=0 ;i<4 ; i++){

		Port_Init(&Port_Config[i]);

	}  

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to set Pwm-Timer Configurations 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	const Pwm_ConfigType*ConfigPtr "Pointer to struct"
*	\Parameters (out):	void
*************************************************************************************************************************/

			Pwm_Init (&Pwm_Config);  


/****************************************************************************************************************************
*	\syntax          :	void Stk_IntCtrlInit (const Stk_ConfigType* ConfigPtr  );  
*	\Description     :  function to Intialize systick Configurations 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	const Stk_ConfigType*ConfigPtr "Pointer to struct"
*	\Parameters (out):	void
*************************************************************************************************************************/

		Stk_Init(&Stk_Config);

/****************************************************************************************************************************
*	\syntax          :	void Exti_Init(const Exti_ConfigType* ConfigPtr)
*	\Description     :  function to set External Interrupts Configurations 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	const Exti_ConfigType*ConfigPtr "Pointer to struct"
*	\Parameters (out):	void
*************************************************************************************************************************/
 
 for(i=0 ; i<2 ; i++){

	 Exti_Init(&Exti_Config[i]);

 }


/****************************************************************************************************************************
*	\syntax          :	void Nvic_IntEnable (IntCtrl_InterruptType InterruptType) 
*	\Description     :  function to Enable  Interrupts 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Non-Reentrant
*	\Parameters (in) :	IntCtrl_InterruptType InterruptType
*	\Parameters (out):	void
*************************************************************************************************************************/


	Nvic_IntEnable (GPIOA_Handler_Indix);
  Nvic_IntEnable (GPIOB_Handler_Indix);
 
/****************************************************************************************************************************
*	\syntax          :	void Exti_EnableInterrupt(Exti_ChannelType Channel)
*	\Description     :  function to enable External Interrupt. 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Exti_ChannelType Channel
*	\Parameters (out):	void
*************************************************************************************************************************/
 
		Exti_EnableInterrupt(EXTI_PA0);
	  Exti_EnableInterrupt(EXTI_PB0);


/****************************************************************************************************************************
*	\syntax			     :	void DIO_WriteChannel(Dio_ChannelType ChannelId , Dio_LevelType Level);	
*	\Description     :  function to write on any Channel"Pin" which takes Pin no. and level 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Channel ID "of type Dio_ChannelType" & DIO Level "of type Dio_Level Type"  
*	\Parameters (out):	void
*	\Return value	   :	void
*************************************************************************************************************************/

	DIO_WriteChannel(PF3, LOW);

	
	while(1){

		Nvic_SetPendingFlag (GPIOA_Handler_Indix);


				
/*******************************************************FIRST IMPLEMENTATION USING PWM*********************************************************/

/*********************************************************CHECKING FOR SW1 STATUS***************************************************************/

/*
		if(Sw1_gVariable==1){

		Stk_SetBusyWait(240000);  		//20ms blocking delay to avoid debouncing

			TURN_ON_TIME++;
			TURN_OFF_TIME--;
		
	Sw1_gVariable=0;
	}

*/

/***********************************************************CHECKING FOR SW2 STATUS*********************************************/	

/*
		if(Sw2_gVariable==1){

		Stk_SetBusyWait(240000);  		//20ms blocking delay to avoid debouncing			
			TURN_ON_TIME--;
			TURN_OFF_TIME++;
		
		Sw2_gVariable=0;

		}	

*/

/****************************************************************Start PWM******************************************************/


		
	/*	Pwm_StartTimer(PWM_TIMER1_16_32 , 0xFFFF , 0xFFFF); */ 
		
	  

			
/***************************************************LIGHT LED by increasing duty cycle**********************************************/
		
	/*
		for(i=0xFFFF ; i > 0 ;i--){
			
			Pwm_SetMatchValue(PWM_TIMER1_16_32 , i);
			Stk_SetBusyWait(0xF);

		}	
	*/

/**********************************************************Turn On Time Delay**************************************************************/
		/*
		for(i=0;i<=TURN_ON_TIME;i++){
			
						Stk_SetBusyWait(12000000);  		//1 second blocking delay	
				}
	
*/
	

/****************************************************************DIM LED  by decreasing duty cyle********************************/

/*
		for(i=0 ; i < 0xFFFF ;i++){

					Pwm_SetMatchValue(PWM_TIMER1_16_32 , i);   
					Stk_SetBusyWait(0xF);

				}

*/

/**********************************************************Turn Off Time Delay*****************************************************/

	/*			for(i=0;i<=TURN_OFF_TIME;i++){
			
					Stk_SetBusyWait(12000000);  		//1 second blocking delay 	
				}

*/
				
/****************************************************************Stop PWM**********************************************************/

					/*
			Pwm_StopTimer(PWM_TIMER1_16_32); 
	    */



		

/*******************************ANOTHER IMPLEMENTATION WITHOUT USING PWM FOR SIMULATION PURPOSE AS WE CAN'T SIMULATE PWM IN KIEL**********/	



/********************************************************CHECKING FOR SW1 STATUS*****************************************************/


	if(Sw1_gVariable==1){

		Stk_SetBusyWait(240000);  		/*20ms blocking delay to avoid debouncing*/

			TURN_ON_TIME++;
			TURN_OFF_TIME--;
		
	Sw1_gVariable=0;
	}	


/******************************************************CHECKING FOR SW2 STATUS******************************************************/	


	if(Sw2_gVariable==1){

		Stk_SetBusyWait(240000);  		/*20ms blocking delay to avoid debouncing*/
			
			TURN_ON_TIME--;
			TURN_OFF_TIME++;
		
	Sw2_gVariable=0;
	}	


/*****************************************************START LIGHTING AND DIMMING LED************************************************/	

	
		DIO_WriteChannel(PA2, HIGH); 		

			/*ON TIME DURATION*/

			for(i=0;i<=TURN_ON_TIME;i++){
			
					Stk_SetBusyWait(12000000);  		/*1 second blocking delay*/	
			}

		Dio_FlipChannel(PA2);

				/*OFF TIME DURATION*/

			for(i=0; i<=TURN_OFF_TIME ; i++){
			
				Stk_SetBusyWait(12000000);				/*1 second blocking delay*/
			}

	}
	
}	


