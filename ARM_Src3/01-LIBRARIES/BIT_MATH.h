#ifndef BIT_MATH_H
#define BIT_MATH_H

#define BIT_BAND_ALIAS_BASE_ADDRESS            0x42000000    /*BIT BAND ALIAS OFFSET*/
 
#define BIT_BAND_REGION_BASE_ADDRESS           0x40000000    /* BIT BAND REGION OFFSET*/

#define BIT_BANDING(PERIPHRAL_OFFSET , REGISTER_OFFSET , BIT_NUMBER)	   ((volatile uint32*)((BIT_BAND_ALIAS_BASE_ADDRESS) + (((PERIPHRAL_OFFSET) + (REGISTER_OFFSET)) * (32) )))[BIT_NUMBER]




#define SET_BIT(VAR , BIT)         VAR|=(1<<BIT)

#define CLR_BIT(VAR , BIT)         VAR&=~(1<<BIT)

#define GET_BIT(VAR , BIT)        (VAR>>BIT)&1

#define TOG_BIT(VAR , BIT)         VAR^=(1<<BIT)

#endif
