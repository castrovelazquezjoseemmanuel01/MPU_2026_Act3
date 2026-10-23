#ifndef _extin
#define _extin
#include <stm32f10x.h>

extern volatile uint8_t flag;
void EXTI0_IRQHandler (void);
void clean_flag (void);
void extin_count();

#endif