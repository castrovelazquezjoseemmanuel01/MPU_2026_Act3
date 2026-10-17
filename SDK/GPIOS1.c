#include <stm32f10x.h>


void BC_enb(void){
    RCC->APB2ENR |= (1 << 4) | (1 << 2) | (1 << 0); 	//Enable peripheral clocks
}


void init_RP(void){
    GPIOA->CRL &= ~(0xF << 0);												//Configure PA0 as input Pull-Up
    GPIOA->CRL |=  (1 << 3);
    GPIOA->ODR |=  (1 << 0);
}


void init_led_pin(void){
    GPIOC->CRH |= (1 << 21);
}


void init_extin(void){
    AFIO->EXTICR[0] &= ~(0xF << 0);										//Configure EXTI0 Falling Trigger
    EXTI->RTSR      &= ~(1 << 0);
    EXTI->FTSR      |=  (1 << 0);
    EXTI->PR         =  (1 << 0);
    EXTI->IMR       |=  (1 << 0);
    NVIC->ISER[0]    =  (1 << 6);
}
