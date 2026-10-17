#ifndef _extin
#define _extin
#include <stdint.h>

extern volatile uint8_t flag;
void EXTI0_IRQHandler (void);
void clean_flag (void);

#endif