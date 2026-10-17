#include <stm32f10x.h>
#include "leds.h"
volatile uint8_t flag = 0;

void EXTI0_IRQHandler(void){
    EXTI->IMR &= ~(1 << 0);  // Disable EXTI0
    EXTI->PR = (1 << 0);     // Clear pending flag
    flag = 1;               // Set software flag
}

void clean_flag (void){
	if(flag){
			led_blink();
			EXTI->PR = (1 << 0);
			EXTI->IMR |= (1 << 0);
			flag = 0;
			}
}