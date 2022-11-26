#ifndef GPT_PRIVATE_H_
#define GPT_PRIVATE_H_

/****************************************************************************************************************************
											Register Mapping
****************************************************************************************************************************/

#define GPTMPP   0xFC0   /* last register base address*/



#define TIMER0_16_32_BaseAddress          ((volatile uint32*)0x40030000)										
#define TIMER1_16_32_BaseAddress          ((volatile uint32*)0x40031000)
#define TIMER2_16_32_BaseAddress          ((volatile uint32*)0x40032000)
#define TIMER3_16_32_BaseAddress          ((volatile uint32*)0x40033000)
#define TIMER4_16_32_BaseAddress          ((volatile uint32*)0x40034000)
#define TIMER5_16_32_BaseAddress          ((volatile uint32*)0x40035000)



#define TIMER0_32_64_BaseAddress           ((volatile uint32*)0x40036000)										
#define TIMER1_32_64_BaseAddress           ((volatile uint32*)0x40037000)
#define TIMER2_32_64_BaseAddress           ((volatile uint32*)0x4004C000)
#define TIMER3_32_64_BaseAddress           ((volatile uint32*)0x4004D000)
#define TIMER4_32_64_BaseAddress           ((volatile uint32*)0x4004E000)
#define TIMER5_32_64_BaseAddress           ((volatile uint32*)0x4004F000)



typedef struct{

uint32 GPTMCFG;

uint32 GPTMTAMR;

uint32 GPTMTBMR;

uint32 GPTMCTL;

uint32 GPTMSYNC[2];

uint32 GPTMIMR;

uint32 GPTMRIS;

uint32 GPTMMIS;

uint32 GPTMICR;

uint32 GPTMTAILR;

uint32 GPTMTBILR;

uint32 GPTMTAMATCHR;

uint32 GPTMTAMBTCHR;

uint32 GPTMTAPR;

uint32 GPTMTBPR;

uint32 GPTMTAPMR;

uint32 GPTMTBPMR;

uint32 GPTMTAR;

uint32 GPTMTBR;

uint32 GPTMTAV;

uint32 GPTMTBV;

uint32 GPTMRTCPD;

uint32 GPTMTAPS;

uint32 GPTMTBPS;

uint32 GPTMTAPV;

uint32 GPTMTBPV;


}Gpt_RegsType;

const volatile uint32*TimerBaseAddress[12]={

  TIMER0_16_32_BaseAddress  , TIMER1_16_32_BaseAddress 
 ,TIMER2_16_32_BaseAddress  , TIMER3_16_32_BaseAddress
 ,TIMER4_16_32_BaseAddress  , TIMER5_16_32_BaseAddress
 ,TIMER0_32_64_BaseAddress  , TIMER1_32_64_BaseAddress 
 ,TIMER2_32_64_BaseAddress  , TIMER3_32_64_BaseAddress 
 ,TIMER4_32_64_BaseAddress  , TIMER5_32_64_BaseAddress

};
#endif