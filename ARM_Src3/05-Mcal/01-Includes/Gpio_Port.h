/*****************************************************************************************************************************
*FILE DESCRIPTION
*-----------------------------------------------------------------------------------------------------------------------------
*	FILE: Gpio.h

*	Module:   Gpio_H

*	DESCRIPTION: header file for GPIO Periphral interface

*
*****************************************************************************************************************************/

#ifndef GPIO_PORT_H
#define GPIO_PORT_H

/****************************************************************************************************************************
*	GLOBAL DATA TYPES AND STRUCTURES
****************************************************************************************************************************/
typedef enum{

	PPA0 , PPA1 , PPA2 , PPA3 , PPA4 , PPA5 , PPA6 , PPA7 , PPB0 , PPB1 , PPB2 , PPB3 , PPB4 , PPB5 , PPB6 , PPB7,

	PPC0 , PPC1 , PPC2 , PPC3 , PPC4 , PPC5 , PPC6 , PPC7 , PPD0 , PPD1 , PPD2 , PPD3 , PPD4 , PPD5 , PPD6 , PPD7,

	PPE0 , PPE1 , PPE2 , PPE3 , PPE4 , PPE5  , PPF0 , PPF1 , PPF2 , PPF3 , PPF4

}Port_PinType;



typedef enum{

	INPUT , OUTPUT

}Port_PinDirectionType;

typedef enum{

	 DIO , UART , SSI , I2C , PWM , CAN , ADC  

}Port_PinModeType;


typedef enum{

	FLOATING , PULL_UP , PULL_DOWN , OPEN_DRAIN 

}Port_PinInternalAttachType;

typedef enum{

	TWO_mA , FOUR_mA , EIGHT_mA

}Port_PinOutPutCurrentType;



typedef struct {

	Port_PinType			         pinType;
	Port_PinDirectionType            directionType;
	Port_PinModeType	 	     	 pinMode;
	Port_PinInternalAttachType		 PinInternalAttachType;
	Port_PinOutPutCurrentType        pinOutPutCurrentType;


}Port_ConfigType;


/****************************************************************************************************************************
*	GLOBAL CONSTANT MACROS
****************************************************************************************************************************/


#define GPIO_PORTA   0

#define GPIO_PORTB   1

#define GPIO_PORTC   2

#define GPIO_PORTD   3

#define GPIO_PORTE   4

#define GPIO_PORTF   5



/****************************************************************************************************************************
*	GLOBAL FUNCTION PROTOTYPES
****************************************************************************************************************************/


/****************************************************************************************************************************
*	\syntax			 :	C-Language
*	\Description     :	function to set configuration for all GPIO of Mcu and it's Alternative Functions
*	\sync\Async      :	Synchronous
*	\Reentrancy      :	Reentrant
*	\Parameters (in) :	Pointer to Struct
*	\Parameters (out):	void 
*	\Return value	 :	void
*************************************************************************************************************************/

		void Port_Init(const Port_ConfigType* ConfigPtr );
		

#endif 	/*GPIO_PORT_H*/


/***************************************************************************************************************************
*	END OF FILE :Gpio_Port.h
***************************************************************************************************************************/
