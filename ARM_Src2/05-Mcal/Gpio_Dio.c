/******************************************************************************************************************************
*	FILE DESCRIPTION
*	-------------------------------------------------------------------------------------------------------------------------
*				\File 	 : Dio.c

*				\*brief	 :	DIO Source File
*
*				\*details: define Global API's used to Read, Write ,Get, Flip any Channel   
*****************************************************************************************************************************/


/****************************************************************************************************************************

*	INCLUDES

****************************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Gpio_Dio.h"
#include "Gpio_Dio_Cfg.h"
#include "Gpio_Private.h"

/* #define BIT_BANDING(PERIPHRAL_OFFSET , REGISTER_OFFSET , BIT_NUMBER)	((volatile uint32*)((BIT_BAND_ALIAS_BASE_ADDRESS) + (((PERIPHRAL_OFFSET) + (REGISTER_OFFSET)) * (32) )))[BIT_NUMBER]*/


/****************************************************************************************************************************

*	API Implementation:

****************************************************************************************************************************/


/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to raed any DIO Channel  which takes ID of Channel and return level 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	DIO Channel Type "Enum"
*	\Parameters (out):	DIO_LevelType
*************************************************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){

	if(ChannelId <= 42){
		if(ChannelId <= 7){
			return 	BIT_BANDING(APB_GPIO_PORTA_OFFSET , (GPIODATA_OFFSET+0x3FC) , ChannelId);
		}
		else if(ChannelId <= 15){
			return 	BIT_BANDING(APB_GPIO_PORTB_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-8));
		}
		else if(ChannelId <= 23){
			return 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-16));
		}
		else if(ChannelId <= 31){
			return 	BIT_BANDING(APB_GPIO_PORTD_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-24));
		}
		else if(ChannelId <= 37){
			return 	BIT_BANDING(APB_GPIO_PORTE_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-32));
		}
		else if(ChannelId <= 42){
			return 	BIT_BANDING(APB_GPIO_PORTF_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-38));
		}
		else{
			;  
		}
	}
	
}	


/****************************************************************************************************************************
													ANOTHER IMPLEMINTATION
****************************************************************************************************************************/
/*
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){

	if(ChannelId <= 43){

		switch(ChannelId){
		
		case PA0:	return 	BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET+0x3FC  , ChannelId);   
		case PA1:	return 	BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET+0x3FC  , ChannelId);	
		case PA2:	return 	BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET+0x3FC  , ChannelId);
		case PA3:	return 	BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET+0x3FC  , ChannelId);
		case PA4:	return  BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET+0x3FC  , ChannelId);	
		case PA5:	return 	BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET+0x3FC  , ChannelId);	
		case PA6:	return 	BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET+0x3FC  , ChannelId);
		case PA7:	return 	BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET+0x3FC  , ChannelId);

		case PB0:	return 	BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-8));
		case PB1:	return 	BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-8));
		case PB2:	return 	BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-8));
		case PB3:	return 	BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-8));
		case PB4:	return 	BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-8));
		case PB5:	return 	BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-8));
		case PB6:	return 	BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-8));
		case PB7:	return 	BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-8));
		
		case PC0:	return 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET+0x3FC  ,(ChannelId-16));
		case PC1:	return 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-16));
		case PC2:	return 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-16));
		case PC3:	return 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-16));
		case PC4:	return 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-16));
		case PC5:	return 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-16));
		case PC6:	return 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-16));
		case PC7:	return 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-16));
	
		case PD0:	return  BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-24));
		case PD1:	return 	BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-24));
		case PD2:	return 	BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-24));
		case PD3:	return 	BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-24));
		case PD4:	return 	BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-24));
		case PD5:	return 	BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-24));
		case PD6:	return 	BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-24);
		case PD7:	return 	BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-24));
		
		case PE0:	return 	BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-32));
		case PE1:	return 	BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-32));
		case PE2:	return 	BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-32));
		case PE3:	return 	BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-32));
		case PE4:	return 	BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-32);
		case PE5:	return 	BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-32));
	
		case PF0:	return 	BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-38));
		case PF1:	return 	BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-38));
		case PF2:	return 	BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-38));
		case PF3:	return 	BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-38));
		case PF4:	return 	BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-38));
		
		default: break;
		}
	}
}

*/

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to write on any Channel"Pin" which takes Pin no. and level 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Channel ID "of type Dio_ChannelType" & DIO Level "of type Dio_Level Type"  
*	\Parameters (out):	void
*	\Return value	 :	void
*************************************************************************************************************************/


void DIO_WriteChannel(Dio_ChannelType ChannelId , Dio_LevelType Level){

/*ANOTHER EASIER METHOD IS TACKING A CHANNEL ID IN A CONTAINER AND DETERMINE PORT THEN WRITE ONLY 7 LINE BITBANDING CODE*/	
	if(Level==LOW || Level==HIGH){
	
		switch(ChannelId){

		case PA0:	 	BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET+0x3FC  , ChannelId)=Level;   break;
		case PA1:	 	BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET+0x3FC  , ChannelId)=Level;	break;
		case PA2:	 	BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET+0x3FC  , ChannelId)=Level;break;
		case PA3:	 	BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET+0x3FC  , ChannelId)=Level;break;
		case PA4:	  BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET+0x3FC  , ChannelId)=Level;	break;
		case PA5:	 	BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET+0x3FC  , ChannelId)=Level;	break;
		case PA6:	 	BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET+0x3FC  , ChannelId)=Level;break;
		case PA7:	 	BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIODATA_OFFSET+0x3FC  , ChannelId)=Level;break;

		case PB0:	 	BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-8))=Level;break;
		case PB1:		BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-8))=Level;break;
		case PB2:	 	BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-8))=Level;break;
		case PB3:	 	BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-8))=Level;break;
		case PB4:	 	BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-8))=Level;break;
		case PB5:	 	BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-8))=Level;break;
		case PB6:	 	BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-8))=Level;break;
		case PB7:	 	BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-8))=Level;break;
		
		case PC0:	 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET+0x3FC  ,(ChannelId-16))=Level;break;
		case PC1:	 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-16))=Level;break;
		case PC2:	 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-16))=Level;break;
		case PC3:	 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-16))=Level;break;
		case PC4:	 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-16))=Level;break;
		case PC5:	 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-16))=Level;break;
		case PC6:	 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-16))=Level;break;
		case PC7:	 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-16))=Level;break;
	
		case PD0:	  BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-24))=Level;break;
		case PD1:	 	BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-24))=Level;break;
		case PD2:	 	BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-24))=Level;break;
		case PD3:	 	BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-24))=Level;break;
		case PD4:	 	BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-24))=Level;break;
		case PD5:		BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-24))=Level;break;
		case PD6:	 	BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-24))=Level;break;
		case PD7:		BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-24))=Level;break;
		
		case PE0:		BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-32))=Level;break;
		case PE1:	 	BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-32))=Level;break;
		case PE2:	 	BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-32))=Level;break;
		case PE3:	 	BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-32))=Level;break;
		case PE4:	 	BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-32))=Level;break;
		case PE5:	 	BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-32))=Level;break;
	
		case PF0:		BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-38))=Level;break;
		case PF1:	 	BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-38))=Level;break;
		case PF2:	 	BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-38))=Level;break;
		case PF3:	 	BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-38))=Level;break;
		case PF4:		BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIODATA_OFFSET+0x3FC  , (ChannelId-38))=Level; break;
			default: break;
		}		
	
	}
}
/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to read Port"all of it's Pins Level" 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Port ID "of type Dio_PortType"   
*	\Parameters (out):	Dio_PortLevel
*************************************************************************************************************************/

	
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId){

	switch(PortId){
	
	case PORTA: return APB_PORTA->GPIO_DATA[255];
	case PORTB:	return APB_PORTB->GPIO_DATA[255];
	case PORTC:	return APB_PORTC->GPIO_DATA[255];
	case PORTD:	return APB_PORTD->GPIO_DATA[255];
	case PORTE:	return APB_PORTE->GPIO_DATA[255];
	case PORTF:	return APB_PORTF->GPIO_DATA[255];
		default: break;
	}

}
/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to write on Port "all of it's Pin" which takes Port Id. and level 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Port ID  & Port Level 
*	\Parameters (out):	void
*************************************************************************************************************************/


void Dio_WritePort(Dio_PortType PortId , Dio_PortLevelType Level){
	
	switch(PortId){
	
	case PORTA: APB_PORTA->GPIO_DATA[255]=  Level;  break;  /*PIOA_DATA[255]=Level case register definition using #define */
	case PORTB:	APB_PORTB->GPIO_DATA[255]=  Level;  break;
	case PORTC:	APB_PORTC->GPIO_DATA[255]=  Level;	break;
	case PORTD:	APB_PORTD->GPIO_DATA[255]=  Level;	break;
	case PORTE:	APB_PORTE->GPIO_DATA[255]=  Level;	  break;
	case PORTF:	APB_PORTF->GPIO_DATA[255]=  Level;	  break;
	
	}
	
}
/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to flip any Channel"Pin" which takes Pin Id 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Channel ID  
*	\Parameters (out):	Dio_levelType
*************************************************************************************************************************/

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId){
	
	if(ChannelId <= 42){
	
		if(ChannelId <= 7){

			if (BIT_BANDING(APB_GPIO_PORTA_OFFSET , (GPIODATA_OFFSET+0x3FC) , ChannelId) == 1 ){
		
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , (GPIODATA_OFFSET+0x3FC) , ChannelId)= 0;
				
				return LOW;
			}
			else{
				BIT_BANDING(APB_GPIO_PORTA_OFFSET , (GPIODATA_OFFSET+0x3FC) , ChannelId)=1;
				
				return HIGH;
			}
		}
		else if(ChannelId <= 15){
		
			if	( BIT_BANDING(APB_GPIO_PORTB_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-8))==1){
				  BIT_BANDING(APB_GPIO_PORTB_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-8))=0;
				
				return LOW;
			 }
			 else{
				
				BIT_BANDING(APB_GPIO_PORTB_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-8))=1;   /*operation inside array index MISRA doesn't agree :)*/

				return HIGH;
			}
		}
		else if(ChannelId <= 23){
			 	
			if	( BIT_BANDING(APB_GPIO_PORTC_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-16))==1){
				
				  BIT_BANDING(APB_GPIO_PORTC_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-16))=0;

				  return LOW;
			 }
			 else{
				
				BIT_BANDING(APB_GPIO_PORTC_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-16))=1;   /*operation inside array index MISRA doesn't agree :)*/

				return HIGH;
			}
		}
		else if(ChannelId <= 31){
			 	
			if	( BIT_BANDING(APB_GPIO_PORTD_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-24))==1){
				
				  BIT_BANDING(APB_GPIO_PORTD_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-24))=0;

				  return LOW;
			 }
			 else{
				
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-24))=1;   /*operation inside array index MISRA doesn't agree :)*/

				return HIGH;
			}
			
		}
		else if(ChannelId <= 37){
			 	
			if	( BIT_BANDING(APB_GPIO_PORTE_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-32))==1){
				  BIT_BANDING(APB_GPIO_PORTE_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-32))=0;

				  return LOW;
			 }
			 else{
				
				BIT_BANDING(APB_GPIO_PORTE_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-32))=1;   /*operation inside array index MISRA doesn't agree :)*/

				return HIGH;
			}		

		}

		else if(ChannelId <= 42){
			 	
			if	( BIT_BANDING(APB_GPIO_PORTF_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-38))==1){
				  BIT_BANDING(APB_GPIO_PORTF_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-38))=0;

				  return LOW;
			 }
			 else{
				
				BIT_BANDING(APB_GPIO_PORTF_OFFSET , (GPIODATA_OFFSET+0x3FC) , (ChannelId-38))=1;   /*operation inside array index MISRA doesn't agree :) */

				return HIGH;
			}
			
		}
		else{
		 ;
		}
	
	}		

}
/***************************************************************************************************************************
*	END OF FILE :Gpio_Dio.c
***************************************************************************************************************************/

