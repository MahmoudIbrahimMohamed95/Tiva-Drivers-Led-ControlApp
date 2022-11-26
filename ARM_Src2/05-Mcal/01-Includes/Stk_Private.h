#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

#define STK_STCTRL         *((volatile uint32*)(0xE000E000+0x010))

#define STK_STRELOAD       *((volatile uint32*)(0xE000E000+0x014))

#define STK_STCURRENT      *((volatile uint32*)(0xE000E000+0x018))

#endif