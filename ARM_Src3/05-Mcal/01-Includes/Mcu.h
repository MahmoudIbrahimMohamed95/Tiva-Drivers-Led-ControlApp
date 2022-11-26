#ifndef MCU_H_
#define MCU_H_



#define MCU_EXT_RESET        1
#define MCU_POR_RESET        2
#define MCU_BOR_RESET        4
#define MCU_WDT0_RESET       8
#define MCU_SW_RESET  	    16
#define MCU_WDT1_RESET      32
#define MCU_MOSCFAIL_RESET  65536


typedef uint32 Mcu_RawResetType;


typedef enum{

	UNLOCKED , LOCKED

}Mcu_PllStatusType;


typedef enum{

	 MOSC ,PIOSC , PIOSC_DIV_FOUR ,  LFIOSC , HIBERNATION, PIOSC_PLL , MOSC_PLL

}Mcu_ClockType;


typedef enum{

	MCU_WDT0 , MCU_WDT1 , MCU_TIMER0 , MCU_TIMER1  , MCU_TIMER2 , MCU_TIMER3 , MCU_TIMER4 , MCU_TIMER5 , MCU_PORTA 
	
	,MCU_PORTB , MCU_PORTC , MCU_PORTD , MCU_PORTE ,MCU_PORTF , MCU_uDMA , MCU_HIBERNATION_MODULE ,MCU_UART0
	
   ,MCU_UART1, MCU_UART2 , MCU_UART3 , MCU_UART4 , MCU_UART5 , MCU_UART6 , MCU_UART7 ,MCU_SSI3 ,MCU_SSI2 , MCU_SSI1 ,MCU_SSI0

	,MCU_I2C3 , MCU_I2C2 , MCU_I2C1 ,MCU_I2C0 , MCU_USB , MCU_CAN0 , MCU_CAN1 , MCU_ADC0 , MCU_ADC1 ,MCU_ANALOG_COMPARATOR , 
	
	MCU_PWM0 , MCU_PWM1, MCU_QUAD_ENCODER0 ,MCU_QUAD_ENCODER1, MCU_EEPROM ,  MCU_TIMER0_32_64, MCU_TIMER1_32_64 

	,MCU_TIMER2_32_64 , MCU_TIMER3_32_64 , MCU_TIMER4_32_64 , MCU_TIMER5_32_64  

}Mcu_PeriphralClockGates;


typedef enum{

	DISABLE , ENABLE

}Mcu_SwReset;


typedef struct{

Mcu_ClockType            clockType;

Mcu_PeriphralClockGates   periphralClock;


}Mcu_ConfigType;

Mcu_RawResetType Mcu_GetResetRawValue(void);
void Mcu_PerformReset(void);
void Mcu_Init(const Mcu_ConfigType*ConfigPtr);
Std_ReturnType Mcu_InitClock(Mcu_ClockType  ClockSetting);
Std_ReturnType Mcu_DistributePllClock(void);
Mcu_PllStatusType Mcu_GetPllStatus(void);


#endif
