#ifndef SCB_H_
#define SCB_H_

void Scb_PrioritySetUp (void);
void Scb_SysTickIntteruptEnable(void);
void Scb_SysTickIntteruptDISable(void);
void Scb_SysTickSetPendingFlag(void);
void Scb_SysTickClearPendingFlag(void);
 void Scb_SysTickTriggerInterrupt(void);


#define THREE_BIT_GROUP                     (0x0)

#define TWO_BIT_GROUP_ONE_BIT_SUB           (0x5)

#define ONE_BIT_GROUP_TWO_BIT_SUB           (0x6)

#define THREE_BIT_SUB                       (0x7)

#define PRIORITY_SETUP   THREE_BIT_SUB  

#endif