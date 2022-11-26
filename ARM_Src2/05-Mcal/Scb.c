#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include "Scb.h"

#include "Scb_Private.h"

void Scb_PrioritySetUp (void){


 SCB_APINT= ((SCB_APINT & (0x0000FFFF))|((0x05FA)<<16));
 
 SCB_APINT= ((SCB_APINT &(0xFFFFF8FF))  |(PRIORITY_SETUP<<8));

}
/*void Scb_SysTickIntteruptEnable(void){

    SET_BIT(SCB_SYSHNDCTRL , 11);
}
 */
 /*void Scb_SysTickIntteruptDISable(void){

    CLR_BIT(SCB_SYSHNDCTRL , 11);
 }*/
 void Scb_SysTickSetPendingFlag(void){

    SET_BIT(SCB_INTCTRL , 26);
 }
 
 void Scb_SysTickClearPendingFlag(void){

    CLR_BIT(SCB_INTCTRL, 25);
 }
 
 