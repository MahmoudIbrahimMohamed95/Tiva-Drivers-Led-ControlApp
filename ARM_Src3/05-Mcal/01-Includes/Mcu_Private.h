#ifndef MCU_PRIVATE_H
#define	MCU_PRIVATE_H

#define SCB_APINT		    *((volatile uint32*)(0xE000E000+0x008))    /*needed reg from SCB*/ 

#define SCR_RESC	            *((volatile uint32*)(0x400FE000+0x05C))

#define SCR_RCC	                *((volatile uint32*)(0x400FE000+0x060))

#define SCR_RCC2	            *((volatile uint32*)(0x400FE000+0x070))

#define SCR_PLLSTAT             *((volatile uint32*)(0x400FE000+0x168))

#define SCR_RCGCWD		        *((volatile uint32*)(0x400FE000+0x600))

#define SCR_RCGCTIMER		    *((volatile uint32*)(0x400FE000+0x604))

#define SCR_RCGCGPIO		    *((volatile uint32*)(0x400FE000+0x608))

#define SCR_RCGCDMA		        *((volatile uint32*)(0x400FE000+0x60C))

#define SCR_RCGCHIB		        *((volatile uint32*)(0x400FE000+0x614))

#define SCR_RCGCUART		    *((volatile uint32*)(0x400FE000+0x618))

#define SCR_RCGCSSI		        *((volatile uint32*)(0x400FE000+0x661C))

#define SCR_RCGCI2C		        *((volatile uint32*)(0x400FE000+0x620))

#define SCR_RCGCUSB		        *((volatile uint32*)(0x400FE000+0x628))

#define SCR_RCGCCAN		        *((volatile uint32*)(0x400FE000+0x634))

#define SCR_RCGCADC		        *((volatile uint32*)(0x400FE000+0x638))

#define SCR_RCGCACMP		    *((volatile uint32*)(0x400FE000+0x63C))

#define SCR_RCGCPWM		        *((volatile uint32*)(0x400FE000+0x640))

#define SCR_RCGCWTIMER		    *((volatile uint32*)(0x400FE000+0x65C))

#endif
