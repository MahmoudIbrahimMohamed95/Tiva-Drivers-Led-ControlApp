#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Exti_Config.h"
#include "Exti_Private.h"
#include "Exti.h"

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
 
void Exti_Init(const Exti_ConfigType* ConfigPtr){

    if((ConfigPtr->Exti_Channel)<=7) {

            Exti_CallBack[0]=(ConfigPtr->Exti_Notification);

            switch(ConfigPtr->Exti_Level){
 
                case EXTI_RAISING_EDGE:
                    BIT_BANDING(APB_GPIO_PORTA_OFFSET , (GPIOIS_OFFSET) , (ConfigPtr->Exti_Channel))=0;
                    BIT_BANDING(APB_GPIO_PORTA_OFFSET , (GPIOIEV_OFFSET) , (ConfigPtr->Exti_Channel))=1;
                    break;
                case EXTI_FALLING_EDGE:  
                    BIT_BANDING(APB_GPIO_PORTA_OFFSET , (GPIOIS_OFFSET) , (ConfigPtr->Exti_Channel))=0;
                    BIT_BANDING(APB_GPIO_PORTA_OFFSET , (GPIOIEV_OFFSET) , (ConfigPtr->Exti_Channel))=0;
                    break;
                case EXTI_ON_CHANGE:
                    
                    BIT_BANDING(APB_GPIO_PORTA_OFFSET , (GPIOIS_OFFSET) , (ConfigPtr->Exti_Channel))=0;
                    BIT_BANDING(APB_GPIO_PORTA_OFFSET , (GPIOIBE_OFFSET) , (ConfigPtr->Exti_Channel))=1;
                    break;
                case EXTI_HIGH_LEVEl:
                    BIT_BANDING(APB_GPIO_PORTA_OFFSET , (GPIOIS_OFFSET) , (ConfigPtr->Exti_Channel))=1;
                    BIT_BANDING(APB_GPIO_PORTA_OFFSET , (GPIOIEV_OFFSET) , (ConfigPtr->Exti_Channel))=1;
                    break;
                case EXTI_LOW_LEVEL:
                    BIT_BANDING(APB_GPIO_PORTA_OFFSET , (GPIOIS_OFFSET) , (ConfigPtr->Exti_Channel))=1;
                    BIT_BANDING(APB_GPIO_PORTA_OFFSET , (GPIOIEV_OFFSET) , (ConfigPtr->Exti_Channel))=0;
                    break;
                default:break;
            }

    }
    
    else if (((ConfigPtr->Exti_Channel)<=15)){

            Exti_CallBack[1]=(ConfigPtr->Exti_Notification);

            switch(ConfigPtr->Exti_Level){
 
                case EXTI_RAISING_EDGE:
                    BIT_BANDING(APB_GPIO_PORTB_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-8))=0;
                    BIT_BANDING(APB_GPIO_PORTB_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-8))=1;
                    break;
                case EXTI_FALLING_EDGE:  
                    BIT_BANDING(APB_GPIO_PORTB_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-8))=0;
                    BIT_BANDING(APB_GPIO_PORTB_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-8))=0;
                    break;
                case EXTI_ON_CHANGE:
                    
                    BIT_BANDING(APB_GPIO_PORTB_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-8))=0;
                    BIT_BANDING(APB_GPIO_PORTB_OFFSET , (GPIOIBE_OFFSET) , ((ConfigPtr->Exti_Channel)-8))=1;
                    break;
                case EXTI_HIGH_LEVEl:
                    BIT_BANDING(APB_GPIO_PORTB_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-8))=1;
                    BIT_BANDING(APB_GPIO_PORTB_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-8))=1;
                    break;
                case EXTI_LOW_LEVEL:
                    BIT_BANDING(APB_GPIO_PORTB_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-8))=1;
                    BIT_BANDING(APB_GPIO_PORTB_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-8))=0;
                    break;
                default:break;
            }
        
    }
    else if(((ConfigPtr->Exti_Channel)<=23)){
    
            Exti_CallBack[2]=(ConfigPtr->Exti_Notification);

             switch(ConfigPtr->Exti_Level){
 
                case EXTI_RAISING_EDGE:
                    BIT_BANDING(APB_GPIO_PORTC_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-16))=0;
                    BIT_BANDING(APB_GPIO_PORTC_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-16))=1;
                    break;
                case EXTI_FALLING_EDGE:  
                    BIT_BANDING(APB_GPIO_PORTC_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-16))=0;
                    BIT_BANDING(APB_GPIO_PORTC_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-16))=0;
                    break;
                case EXTI_ON_CHANGE:
                    
                    BIT_BANDING(APB_GPIO_PORTC_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-16))=0;
                    BIT_BANDING(APB_GPIO_PORTC_OFFSET , (GPIOIBE_OFFSET) , ((ConfigPtr->Exti_Channel)-16))=1;
                    break;
                case EXTI_HIGH_LEVEl:
                    BIT_BANDING(APB_GPIO_PORTC_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-16))=1;
                    BIT_BANDING(APB_GPIO_PORTC_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-16))=1;
                    break;
                case EXTI_LOW_LEVEL:
                    BIT_BANDING(APB_GPIO_PORTC_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-16))=1;
                    BIT_BANDING(APB_GPIO_PORTC_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-16))=0;
                    break;
                default:break;
            }
        
        
    }
    else if(((ConfigPtr->Exti_Channel)<=31)){
        
            Exti_CallBack[3]=(ConfigPtr->Exti_Notification);

             switch(ConfigPtr->Exti_Level){
 
                case EXTI_RAISING_EDGE:
                    BIT_BANDING(APB_GPIO_PORTD_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-24))=0;
                    BIT_BANDING(APB_GPIO_PORTD_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-24))=1;
                    break;
                case EXTI_FALLING_EDGE:  
                    BIT_BANDING(APB_GPIO_PORTD_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-24))=0;
                    BIT_BANDING(APB_GPIO_PORTD_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-24))=0;
                    break;
                case EXTI_ON_CHANGE:
                    
                    BIT_BANDING(APB_GPIO_PORTD_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-24))=0;
                    BIT_BANDING(APB_GPIO_PORTD_OFFSET , (GPIOIBE_OFFSET) , ((ConfigPtr->Exti_Channel)-24))=1;
                    break;
                case EXTI_HIGH_LEVEl:
                    BIT_BANDING(APB_GPIO_PORTD_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-24))=1;
                    BIT_BANDING(APB_GPIO_PORTD_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-24))=1;
                    break;
                case EXTI_LOW_LEVEL:
                    BIT_BANDING(APB_GPIO_PORTD_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-24))=1;
                    BIT_BANDING(APB_GPIO_PORTD_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-24))=0;
                    break;
                default:break;
            }
        
    }
    else if(((ConfigPtr->Exti_Channel)<=37)){
        
            Exti_CallBack[4]=(ConfigPtr->Exti_Notification);

              switch(ConfigPtr->Exti_Level){
 
                case EXTI_RAISING_EDGE:
                    BIT_BANDING(APB_GPIO_PORTE_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-32))=0;
                    BIT_BANDING(APB_GPIO_PORTE_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-32))=1;
                    break;
                case EXTI_FALLING_EDGE:  
                    BIT_BANDING(APB_GPIO_PORTE_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-32))=0;
                    BIT_BANDING(APB_GPIO_PORTE_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-32))=0;
                    break;
                case EXTI_ON_CHANGE:
                    
                    BIT_BANDING(APB_GPIO_PORTE_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-32))=0;
                    BIT_BANDING(APB_GPIO_PORTE_OFFSET , (GPIOIBE_OFFSET) , ((ConfigPtr->Exti_Channel)-32))=1;
                    break;
                case EXTI_HIGH_LEVEl:
                    BIT_BANDING(APB_GPIO_PORTE_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-32))=1;
                    BIT_BANDING(APB_GPIO_PORTE_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-32))=1;
                    break;
                case EXTI_LOW_LEVEL:
                    BIT_BANDING(APB_GPIO_PORTE_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-32))=1;
                    BIT_BANDING(APB_GPIO_PORTE_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-32))=0;
                    break;
                default:break;
            }
       
        
    }
    else if(( (ConfigPtr->Exti_Channel)<=42)){

            Exti_CallBack[5]=(ConfigPtr->Exti_Notification);

              switch(ConfigPtr->Exti_Level){
 
                case EXTI_RAISING_EDGE:
                    BIT_BANDING(APB_GPIO_PORTF_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-38))=0;
                    BIT_BANDING(APB_GPIO_PORTF_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-38))=1;
                    break;
                case EXTI_FALLING_EDGE:  
                    BIT_BANDING(APB_GPIO_PORTF_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-38))=0;
                    BIT_BANDING(APB_GPIO_PORTF_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-38))=0;
                    break;
                case EXTI_ON_CHANGE:
                    
                    BIT_BANDING(APB_GPIO_PORTF_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-38))=0;
                    BIT_BANDING(APB_GPIO_PORTF_OFFSET , (GPIOIBE_OFFSET) , ((ConfigPtr->Exti_Channel)-38))=1;
                    break;
                case EXTI_HIGH_LEVEl:
                    BIT_BANDING(APB_GPIO_PORTF_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-38))=1;
                    BIT_BANDING(APB_GPIO_PORTF_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-38))=1;
                    break;
                case EXTI_LOW_LEVEL:
                    BIT_BANDING(APB_GPIO_PORTF_OFFSET , (GPIOIS_OFFSET) , ((ConfigPtr->Exti_Channel)-38))=1;
                    BIT_BANDING(APB_GPIO_PORTF_OFFSET , (GPIOIEV_OFFSET) , ((ConfigPtr->Exti_Channel)-38))=0;
                    break;
                default:break;
            }
       
    }
    else{
        ;
        }

}



/****************************************************************************************************************************
*	\syntax          :	void Exti_EnableInterrupt(Exti_ChannelType Channel)
*	\Description     :  function to enable External Interrupt. 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Exti_ChannelType Channel
*	\Parameters (out):	void
*************************************************************************************************************************/
 

void Exti_EnableInterrupt(Exti_ChannelType Channel){

    if(Channel <= 7){
			BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOIM_OFFSET , Channel)=1;
		}
		else if(Channel <= 15){
			BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOIM_OFFSET , (Channel-8))=1;
		}
		else if(Channel <= 23){
			 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIOIM_OFFSET , (Channel-16))=1;
		}
		else if(Channel <= 31){
				BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOIM_OFFSET , (Channel-24))=1;
		}
		else if(Channel <= 37){
			 	BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOIM_OFFSET, (Channel-32))=1;
		}
		else if(Channel <= 42){
			 	BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOIM_OFFSET , (Channel-38))=1;
		}
		else{
			;  
		}

}



/****************************************************************************************************************************
*	\syntax          :	void Exti_DisableInterrupt(Exti_ChannelType Channel)
*	\Description     :  function to disable External Interrupt. 
*	\sync\Async      :	Synchronous
*	\Reentrancy      : 	Reentrant
*	\Parameters (in) :	Exti_ChannelType Channel
*	\Parameters (out):	void
*************************************************************************************************************************/
 

void Exti_DisableInterrupt(Exti_ChannelType Channel){

    if(Channel <= 7){
			BIT_BANDING(APB_GPIO_PORTA_OFFSET , GPIOIM_OFFSET , Channel)=0;
		}
		else if(Channel <= 15){
			BIT_BANDING(APB_GPIO_PORTB_OFFSET , GPIOIM_OFFSET , (Channel-8))=0;
		}
		else if(Channel <= 23){
			 	BIT_BANDING(APB_GPIO_PORTC_OFFSET , GPIOIM_OFFSET , (Channel-16))=0;
		}
		else if(Channel <= 31){
			 	BIT_BANDING(APB_GPIO_PORTD_OFFSET , GPIOIM_OFFSET , (Channel-24))=0;
		}
		else if(Channel <= 37){
			 	BIT_BANDING(APB_GPIO_PORTE_OFFSET , GPIOIM_OFFSET, (Channel-32))=0;
		}
		else if(Channel <= 42){
			 	BIT_BANDING(APB_GPIO_PORTF_OFFSET , GPIOIM_OFFSET , (Channel-38))=0;
		}
		else{
			;  
		}

} 




/****************************************************************************************************************************
*	\syntax          :	
*	\Description     :  GPIO's ISR HAndlers 
*	\sync\Async      :	ASynchronous
*	\Reentrancy      : 	Based on if you enable Interrupt Nesting
*	\Parameters (in) :	void
*	\Parameters (out):	void
*************************************************************************************************************************/
 

void GPIOA_Handler(void){


    if(Exti_CallBack[0] != NULL_PTR){

        (*Exti_CallBack[0])();

    }
    APB_GPIOA_ICR=0xFF;
}

void GPIOB_Handler(void){

    
    if(Exti_CallBack[1] != NULL_PTR){

        (*Exti_CallBack[1])();

    }
    APB_GPIOB_ICR=0xFF;
}

void GPIOC_Handler(void){

    
    if(Exti_CallBack[2] != NULL_PTR){

        (*Exti_CallBack[2])();

    }
    APB_GPIOC_ICR=0xFF;
}

void GPIOD_Handler(void){

    
    if(Exti_CallBack[3] != NULL_PTR){

        (*Exti_CallBack[3])();

    }
    APB_GPIOD_ICR=0xFF;

}

void GPIOE_Handler(void){

    
    if(Exti_CallBack[4] != NULL_PTR){

        (*Exti_CallBack[4])();

    }
    APB_GPIOE_ICR=0xFF;

}    

void GPIOF_Handler(void){

    
    if(Exti_CallBack[5] != NULL_PTR){

        (*Exti_CallBack[5])();

    }
    APB_GPIOF_ICR=0xFF;

}
