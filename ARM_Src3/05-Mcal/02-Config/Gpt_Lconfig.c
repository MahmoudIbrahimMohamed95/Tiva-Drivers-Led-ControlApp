
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Gpt.h"
#include "Gpt_Main.h"

Gpt_ConfigType Gpt_Config[2]={{TIMER0_16_32 , 0x7 , 0xFFFF , PERIODIC ,Gpt_TestISR } , {TIMER3_32_64 , 0x15 , 0xFFFFFFFF , PERIODIC , NULL_PTR}};

