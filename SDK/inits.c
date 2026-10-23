#include <stm32f10x.h>


void init_RCC_APB2(void){
	//Enable APB2 for USART, GPIOA,C and AFIO
    RCC->APB2ENR |= (1 << 14) | (1 << 4) | (1 << 2) | (1 << 0);
}


void init_RP(void){
	//Configure PA0 as input Pull-Up
    GPIOA->CRL &= ~(0xF << 0);				
    GPIOA->CRL |=  (1 << 3);
    GPIOA->ODR |=  (1 << 0);
}


void init_led_pin(void){
	//Configure PC13 as output at 50MHz
    GPIOC->CRH |= (1 << 21);
}


void init_extin(void){
	//Configure EXTI0
    AFIO->EXTICR[0] &= ~(0xF << 0);
    EXTI->RTSR      &= ~(1 << 0);
    EXTI->FTSR      |=  (1 << 0);
    EXTI->PR         =  (1 << 0);
    EXTI->IMR       |=  (1 << 0);
    NVIC->ISER[0]    =  (1 << 6);
}

void init_usart (void){
	
	//PA10=RX1 input with pullup
		GPIOA->CRH &= ~((1 << 9)|(1 << 8));							//reset
		GPIOA->CRH |= (1 << 10); 												//floating input
	
	//PA9=TX1 output open drain,alt. func.
		GPIOA->CRH |= (1 << 7)|(1 << 6);	 							//alternate open drain
		GPIOA->CRH |= (1 << 5)|(1 << 4); 								//50 Mhz
	
	//configure USART1
		USART1->CR1 |= ((1 << 13)|(1 << 3)|(1 << 2)); 	//enable: usart, transmit & receive
		USART1->BRR = 7500;															//baud rate 72,000,000/9,600 = 7,500
}
