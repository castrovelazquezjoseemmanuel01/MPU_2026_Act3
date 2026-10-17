#include <stm32f10x.h>

void gpio_cnf(void){
	RCC->APB2ENR |=(1 << 4);
	GPIOC->CRH |= (1 << 21);
	
	
}
