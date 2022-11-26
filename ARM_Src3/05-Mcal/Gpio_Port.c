/******************************************************************************************************************************
*	FILE DESCRIPTION
*	-------------------------------------------------------------------------------------------------------------------------
*				\File 	 : Port.c

*				\*brief	 : Port Driver Implementation.
*
*				\*details:	Source file for GPIO Periphral Interface 
*****************************************************************************************************************************/


/****************************************************************************************************************************

*	INCLUDES

****************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Gpio_Port.h"
#include "Gpio_Port_Cfg.h"
#include "Gpio_Private.h"

/******************************************************************************************************************************************

*GLOBAL FUNCTION PROTOTYPE

*******************************************************************************************************************************************/

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to set configuration for all GPIO of Mcu and it's Alternative Functions 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	pointer to Struct of Configurations
*	\Parameters (out):	void
*	\Return value	 :	void
*************************************************************************************************************************/
 
void Port_Init(const Port_ConfigType* ConfigPtr ){

	 uint8 pinIndix=0;

   uint8 portType=0;

	if((ConfigPtr->pinType)<=7){
		
		pinIndix= ConfigPtr->pinType;
		portType= GPIO_PORTA;
	}	

	else if((ConfigPtr->pinType)<=15){
		
		pinIndix= (ConfigPtr->pinType) - 8;
		portType= GPIO_PORTB;
	}

	else if((ConfigPtr->pinType)<=23){
		
		pinIndix= (ConfigPtr->pinType) - 16;
		portType= GPIO_PORTC;
	}

	else if((ConfigPtr->pinType)<=31){
		
		pinIndix= (ConfigPtr->pinType) - 24 ;
		portType= GPIO_PORTD;
	}
	
	else if((ConfigPtr->pinType)<=37){
		
		pinIndix= (ConfigPtr->pinType) - 32 ;
		portType= GPIO_PORTE;
	}
	
	else if((ConfigPtr->pinType)<=42){
		
		pinIndix= (ConfigPtr->pinType) - 38 ;
		portType= GPIO_PORTF;
	}
	else{
		;
	}
	
	
	switch(portType){
	
	case GPIO_PORTA:
		APB_PORTA->GPIOLOCK = 0x4C4F434B;
		BIT_BANDING(APB_GPIO_PORTA_OFFSET , (GPIODATA_OFFSET+0x3FC) , pinIndix)= 0 ;
	  BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOCR_OFFSET ,   pinIndix)= 1 ;
		BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODEN_OFFSET , pinIndix)= 1 ;

		break;
	case GPIO_PORTB:
		APB_PORTB->GPIOLOCK = 0x4C4F434B;
		BIT_BANDING(APB_GPIO_PORTB_OFFSET , (GPIODATA_OFFSET+0x3FC) , pinIndix)= 0 ;
		BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOCR_OFFSET ,   pinIndix)= 1 ;
		BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODEN_OFFSET , pinIndix)= 1 ;

		break;
	
	case GPIO_PORTC:
			APB_PORTC->GPIOLOCK = 0x4C4F434B;
		  BIT_BANDING(APB_GPIO_PORTC_OFFSET , (GPIODATA_OFFSET+0x3FC) , pinIndix)= 0 ;
			BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIOCR_OFFSET ,   pinIndix)= 1 ;
			BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODEN_OFFSET , pinIndix)= 1 ;
  	break;
	case GPIO_PORTD:
				APB_PORTD->GPIOLOCK = 0x4C4F434B;
        BIT_BANDING(APB_GPIO_PORTD_OFFSET , (GPIODATA_OFFSET+0x3FC) , pinIndix)= 0 ;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOCR_OFFSET ,   pinIndix)= 1 ;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODEN_OFFSET , pinIndix)= 1 ;
		break;
	
	case GPIO_PORTE:
		APB_PORTE->GPIOLOCK = 0x4C4F434B;
		BIT_BANDING(APB_GPIO_PORTE_OFFSET , (GPIODATA_OFFSET+0x3FC) , pinIndix)= 0 ;
		BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOCR_OFFSET ,   pinIndix)= 1 ;
		BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODEN_OFFSET , pinIndix)= 1 ;
  
  	break;
	
	case GPIO_PORTF:
		APB_PORTF->GPIOLOCK = 0x4C4F434B;
		BIT_BANDING(APB_GPIO_PORTF_OFFSET , (GPIODATA_OFFSET+0x3FC) , pinIndix)= 0 ;
		BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOCR_OFFSET ,   pinIndix)= 1 ;
		BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODEN_OFFSET , pinIndix)= 1 ;
 
  	break;

	default:break;

	}

	switch(ConfigPtr->directionType){
	
	case INPUT:
	case OUTPUT:

		if(portType == GPIO_PORTA){
				
			BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODIR_OFFSET , pinIndix)= ConfigPtr->directionType ;

			break;
		}

		else if(portType == GPIO_PORTB){
			
			BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODIR_OFFSET , pinIndix)= ConfigPtr->directionType ;

			break;
		}
		
		else if(portType == GPIO_PORTC){

			BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODIR_OFFSET , pinIndix)= ConfigPtr->directionType ;
			
			break;
		}
		
		else if(portType == GPIO_PORTD){

			BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODIR_OFFSET , pinIndix)= ConfigPtr->directionType ;

			break;
		}
		
		else if(portType == GPIO_PORTE){

			BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODIR_OFFSET , pinIndix)= ConfigPtr->directionType ;

			break;
		}
		
		else if(portType == GPIO_PORTF){

			BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODIR_OFFSET , pinIndix)= ConfigPtr->directionType ;

			break;
		}
		else{
			break;
		}
		
	default:

		break;	

	}
	
	switch(ConfigPtr->pinMode){
	
		case DIO :
			break;
		case UART:
			if(portType == GPIO_PORTA){

				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 1 ;
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 0 ;
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
				break;
			}
			else if(portType == GPIO_PORTB){
				
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 1 ;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 0 ;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
				break;
			
			}
			else if(portType == GPIO_PORTC){
				
				BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 1 ; /*clear it case u1Rx OR u1Tx*/
				BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 0 ; /*set it case u1Rx OR u1Tx */
				BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
				break;
			}
			
			else if(portType == GPIO_PORTD){
				
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 1 ; /*clear it case u1Rx OR u1Tx*/
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 0 ; /*set it case u1Rx OR u1Tx */
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
				break;
			}
			
			else if(portType == GPIO_PORTE){
				
				BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 1 ; /*clear it case u1Rx OR u1Tx*/
				BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 0 ; /*set it case u1Rx OR u1Tx */
				BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
				break;
			}
			
		case SSI :
			
			if(portType == GPIO_PORTA){

				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 0 ;
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 1 ;
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
				break;
			}
			
			else if(portType == GPIO_PORTB){

				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 0 ;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 1 ;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
				break;
			}
			
			else if(portType == GPIO_PORTD){

				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 0 ;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 1 ;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
				break;
			}
			
			else if(portType == GPIO_PORTF){

				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 0 ; /*set it case SSI3*/
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 1 ; /*Clear it case SSI3*/
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
				break;
			}
			
		case I2C :
			
		
			if(portType == GPIO_PORTA){

				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 1 ;
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 1 ;
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
				break;
			}
			
			if(portType == GPIO_PORTB){

				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 1 ;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 1 ;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
				break;
			}
			
			if(portType == GPIO_PORTD){

				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 1 ;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 1 ;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
				break;
			}
			
			if(portType == GPIO_PORTE){

				BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 1 ;
				BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 1 ;
				BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
				break;
			}
		
			break;
		
		case PWM :
		
		if(portType == GPIO_PORTB){
		
			BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
			BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 1 ;
			BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 1 ;
			BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 1 ;
			BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
			break;
		}

		else if(portType == GPIO_PORTC){

			BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
			BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 1 ;
			BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 1 ;
			BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 1 ;
			BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
			break;
		}

		else if(portType == GPIO_PORTD){

			if(pinIndix != 7){
			BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
			BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 1 ;
			BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 1 ;
			BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 1 ;
			BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
			break;

			}

			else{
				APB_PORTD->GPIOLOCK = 0x4C4F434B;
				APB_PORTD->GPIOCR =   0xFF;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 1 ;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 1 ;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 1 ;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
				
				break;
			}

		}
		else if(portType == GPIO_PORTF){

			if(pinIndix != 0){
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 1 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 1 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 1 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 0 ;
				break;
			}

			else{

				APB_PORTF->GPIOLOCK = 0x4C4F434B;
				APB_PORTF->GPIOCR =   0xFF;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET  , GPIOPCTL_OFFSET ,((pinIndix*4)+0))= 1 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET  ,((pinIndix*4)+1))= 1 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET  ,((pinIndix*4)+2))= 1 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET  ,((pinIndix*4)+3))= 0 ;
				
				break;
			}
		}
			
		
		case CAN :

			if(portType == GPIO_PORTA){

				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 0 ;
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 0 ;
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 1 ;
				break;
			}
			
			else if(portType == GPIO_PORTB){

				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 0 ;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 0 ;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 1 ;
				break;
			}
			
			else if(portType == GPIO_PORTE){

				BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 0 ;
				BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 0 ;
				BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 1 ;
				break;
			}
			else if(portType == GPIO_PORTF){
				
				
			if(pinIndix != 0){
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+0))= 0 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+1))= 0 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET , ((pinIndix*4)+3))= 1 ;
				break;
			}

			else{

				APB_PORTF->GPIOLOCK = 0x4C4F434B;
				APB_PORTF->GPIOCR =   0xFF;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOAFSEL_OFFSET , (pinIndix))= 1 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET  , GPIOPCTL_OFFSET ,((pinIndix*4)+0))= 0 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET  ,((pinIndix*4)+1))= 0 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET  ,((pinIndix*4)+2))= 0 ;
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPCTL_OFFSET  ,((pinIndix*4)+3))= 1 ;
				
				break;
			}
		}
			break;

		case ADC :			
			
			if(portType == GPIO_PORTB){

			  BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODEN_OFFSET , pinIndix)=  0;
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOAMSEL_OFFSET , pinIndix)= 1 ;
				break;
			}
			
			if(portType == GPIO_PORTD){
				
			  BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODEN_OFFSET , pinIndix)=  0;
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOAMSEL_OFFSET , pinIndix)= 1 ;
				break;
			}
			
			if(portType == GPIO_PORTE){
				
			  BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODEN_OFFSET , pinIndix)=  0;
				BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOAMSEL_OFFSET , pinIndix)= 1 ;
				break;
			}
			break ;

		default:
			
			break;	
	}

	switch(ConfigPtr->PinInternalAttachType){
	
		case FLOATING : break;
		
		case OPEN_DRAIN :  	
		
		if(portType == GPIO_PORTA){
				
			BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOODR_OFFSET , pinIndix)= 1 ;

			break;
		}

		else if(portType == GPIO_PORTB){
			
			BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOODR_OFFSET , pinIndix)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTC){

			BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIOODR_OFFSET , pinIndix)= 1;
			
			break;
		}
		
		else if(portType == GPIO_PORTD){

			BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOODR_OFFSET , pinIndix)= 1 ;

			break;
		}
		
		else if(portType == GPIO_PORTE){

			BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOODR_OFFSET , pinIndix)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTF){

			BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOODR_OFFSET , pinIndix)= 1;

			break;
		}
		else{
			break;
		}
	
	
		case PULL_UP :   
		
		
		if(portType == GPIO_PORTA){
				
			BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPUR_OFFSET , pinIndix)= 1 ;

			break;
		}

		else if(portType == GPIO_PORTB){
			
			BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPUR_OFFSET , pinIndix)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTC){

			BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIOPUR_OFFSET , pinIndix)= 1;
			
			break;
		}
		
		else if(portType == GPIO_PORTD){

			BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPUR_OFFSET , pinIndix)= 1 ;

			break;
		}
		
		else if(portType == GPIO_PORTE){

			BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOPUR_OFFSET , pinIndix)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTF){

			BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPUR_OFFSET , pinIndix)= 1;

			break;
		}
		else{
			break;
		}

		case PULL_DOWN  :	
		
		
		if(portType == GPIO_PORTA){
				
			BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOPDR_OFFSET , pinIndix)= 1 ;

			break;
		}

		else if(portType == GPIO_PORTB){
			
			BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOPDR_OFFSET , pinIndix)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTC){

			BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIOPDR_OFFSET , pinIndix)= 1;
			
			break;
		}
		
		else if(portType == GPIO_PORTD){

			BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOPDR_OFFSET , pinIndix)= 1 ;

			break;
		}
		
		else if(portType == GPIO_PORTE){

			BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOPDR_OFFSET , pinIndix)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTF){

			BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOPDR_OFFSET , pinIndix)= 1;

			break;
		}
		else{
			break;
		}
	
		default:

			break;
		
	}

	switch(ConfigPtr->pinOutPutCurrentType){
	
	case TWO_mA:
	
			
		if(portType == GPIO_PORTA){
				
			BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODR2R_OFFSET , pinIndix)= 1 ;

			break;
		}

		else if(portType == GPIO_PORTB){
			
			BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODR2R_OFFSET , pinIndix)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTC){

			BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODR2R_OFFSET , pinIndix)= 1;
			
			break;
		}
		
		else if(portType == GPIO_PORTD){

			BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODR2R_OFFSET , pinIndix)= 1 ;

			break;
		}
		
		else if(portType == GPIO_PORTE){

			BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODR2R_OFFSET , pinIndix)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTF){

			BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODR2R_OFFSET , pinIndix)= 1;

			break;
		}
		else{
			break;
		}
	
	
	
	
	case FOUR_mA:
			
		if(portType == GPIO_PORTA){
				
			BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODR4R_OFFSET , pinIndix)= 1 ;

			break;
		}

		else if(portType == GPIO_PORTB){
			
			BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODR4R_OFFSET , pinIndix)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTC){

			BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODR4R_OFFSET , pinIndix)= 1;
			
			break;
		}
		
		else if(portType == GPIO_PORTD){

			BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODR4R_OFFSET , pinIndix)= 1 ;

			break;
		}
		
		else if(portType == GPIO_PORTE){

			BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODR4R_OFFSET , pinIndix)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTF){

			BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODR4R_OFFSET , pinIndix)= 1;

			break;
		}
		else{
			break;
		}
	
	
	case EIGHT_mA:
		
		if(portType == GPIO_PORTA){
				
			BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODR8R_OFFSET , pinIndix)= 1 ;

			break;
		}

		else if(portType == GPIO_PORTB){
			
			BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODR8R_OFFSET , pinIndix)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTC){

			BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODR8R_OFFSET , pinIndix)= 1;
			
			break;
		}
		
		else if(portType == GPIO_PORTD){

			BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODR8R_OFFSET , pinIndix)= 1 ;

			break;
		}
		
		else if(portType == GPIO_PORTE){
 
			BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODR8R_OFFSET , pinIndix)= 1;

			break;
		}
		
		else if(portType == GPIO_PORTF){

			BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODR8R_OFFSET , pinIndix)= 1;

			break;
		}
		else{
			break;
		}
	
		default: break;
	
	}
	
	
}


/*************************************************************************************************************************

* 	END OF FILE: Gpio_Port.c

**************************************************************************************************************************/