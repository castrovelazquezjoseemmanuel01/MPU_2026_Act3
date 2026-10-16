#include <stm32f10x.h>
#include "leds.h"


void EXTI0_IRQHandler(void){
    if(EXTI->PR & (1 << 0)){
        EXTI->IMR &= ~(1 << 0);		//Mask EXTI0
        EXTI->PR = (1 << 0);			//Clean flag
        delay_ms(21);							//Filters out button bounces
				led_blink();
				EXTI->IMR	|=  (1 << 0);
		}
}