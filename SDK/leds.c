#include <stm32f10x.h>

// Delay
void delay_ms(uint16_t t){
    volatile unsigned long j = 0;

    for(uint16_t i = 0; i < t; i++)
        for(j = 0; j < 6000; j++){
        }
}

// Blink LED three times
void led_blink(void){
    for(int x = 0; x < 3; x++){
        GPIOC->ODR &= ~(1 << 13);
        delay_ms(100);
        GPIOC->ODR |= (1 << 13);
        delay_ms(100);
    }
}