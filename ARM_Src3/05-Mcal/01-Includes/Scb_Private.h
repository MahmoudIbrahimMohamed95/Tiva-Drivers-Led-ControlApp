#ifndef SCB_PRIVATE_H_
#define SCB_PRIVATE_H_

#define SCB_ACTLR            *((volatile uint32*)(0xE000E000+0x008))
#define SCB_CPUID            *((volatile uint32*)(0xE000E000+0xD00))
#define SCB_INTCTRL          *((volatile uint32*)(0xE000E000+0xD04))
#define SCB_VTABLE           *((volatile uint32*)(0xE000E000+0xD08))
#define SCB_APINT	    	 *((volatile uint32*)(0xE000E000+0xD0C))
#define SCB_SYSCTRL          *((volatile uint32*)(0xE000E000+0xD10))
#define SCB_CFGCTRL          *((volatile uint32*)(0xE000E000+0xD14))
#define SCB_SYSPRI1          *((volatile uint32*)(0xE000E000+0xD18))
#define SCB_SYSPRI2          *((volatile uint32*)(0xE000E000+0xD1C))
#define SCB_SYSPRI3          *((volatile uint32*)(0xE000E000+0xD20))
#define SCB_SYSHNDCTRL       *((volatile uint32*)(0xE000E000+0xD24))
#define SCB_FAULTSTAT        *((volatile uint32*)(0xE000E000+0xD28))
#define SCB_HFAULTSTAT       *((volatile uint32*)(0xE000E000+0xD2C))
#define SCB_MMADDR           *((volatile uint32*)(0xE000E000+0xD34))
#define SCB_FAULTADDR        *((volatile uint32*)(0xE000E000+0xD38))



#endif