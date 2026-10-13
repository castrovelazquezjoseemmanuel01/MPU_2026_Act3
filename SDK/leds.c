#include <stm32f10x.h>

void led_on_off(void){
	GPIOC->ODR &= ~(1 << 13);
	for (volatile uint32_t i=0; i < 800000 ; i++){
	}
	GPIOC->ODR |=(1 << 13);
	for (volatile uint32_t i=0; i < 800000; i++){
	}
}
void init_gpioc(void){
	RCC->APB2ENR |=(1 << 4);
	GPIOC->CRH |= (1 << 21);
}
