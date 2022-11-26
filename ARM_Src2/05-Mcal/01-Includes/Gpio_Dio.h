/*****************************************************************************************************************************
*FILE DESCRIPTION
*-----------------------------------------------------------------------------------------------------------------------------
*		FILE: Gpio_DIO.h

*	Module:   Gpio_DIO_H

*DESCRIPTION: header file for GPIO_Dio Periphral interface

*
*****************************************************************************************************************************/

#ifndef GPIO_DIO_H_
#define GPIO_DIO_H_

/****************************************************************************************************************************
*	GLOBAL DATA TYPES AND STRUCTURES
****************************************************************************************************************************/

typedef enum{

	PA0 , PA1 , PA2 , PA3 , PA4 , PA5 , PA6 , PA7 , PB0 , PB1 , PB2 , PB3 , PB4 , PB5 , PB6 , PB7,

	PC0 , PC1 , PC2 , PC3 , PC4 , PC5 , PC6 , PC7 , PD0 , PD1 , PD2 , PD3 , PD4 , PD5 , PD6 , PD7,

	PE0 , PE1 , PE2 , PE3 , PE4 , PE5  , PF0 , PF1 , PF2 , PF3 , PF4

}Dio_ChannelType;

typedef enum{

	PORTA , PORTB , PORTC , PORTD , PORTE , PORTF

}Dio_PortType;

typedef enum{

	 LOW , HIGH 

}Dio_LevelType;

typedef uint32 Dio_PortLevelType ;   /* uint32 not uint8 to avoid warning of implicit conversion*/


/****************************************************************************************************************************
*	GLOBAL FUNCTION PROTOTYPES
****************************************************************************************************************************/



/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to raed any DIO Channel  which takes ID of Channel and return level 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	DIO Channel Type "Enum"
*	\Parameters (out):	DIO_LevelType
*************************************************************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);



/****************************************************************************************************************************
*	\syntax			 :	void DIO_WriteChannel(Dio_ChannelType ChannelId , Dio_LevelType Level);	
*	\Description     :  function to write on any Channel"Pin" which takes Pin no. and level 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Channel ID "of type Dio_ChannelType" & DIO Level "of type Dio_Level Type"  
*	\Parameters (out):	void
*	\Return value	 :	void
*************************************************************************************************************************/

void DIO_WriteChannel(Dio_ChannelType ChannelId , Dio_LevelType Level);


/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to read Port"all of it's Pins Level" 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Port ID "of type Dio_PortType"   
*	\Parameters (out):	Dio_PortLevel
*************************************************************************************************************************/

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);


/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to write on Port "all of it's Pin" which takes Port Id. and level 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Port ID  & Port Level 
*	\Parameters (out):	void
*************************************************************************************************************************/


void Dio_WritePort (Dio_PortType PortId , Dio_PortLevelType Level);

/****************************************************************************************************************************
*	\syntax:	
*	\Description     :  function to flip any Channel"Pin" which takes Pin Id 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Channel ID  
*	\Parameters (out):	Dio_levelType
*************************************************************************************************************************/

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

#endif 	/*DIO_H*/

/***************************************************************************************************************************
*	END OF FILE :GPIO_DIO_h_
***************************************************************************************************************************/
