//Karla Yammilet Martinez Pichal
//Luis Elias Valle Velázquez
//Galilea Yamile Sanchez Andrade
//José Emmanuel Castro Velázquez

//Juan Carlos Hernandez Aguilar
//Diego Alan Gonzalez Roero

#include	<stm32f10x.h>
#include "FISR.h"
#include "inits.h"
#include "extin.h"
#include "usart.h"
#include "times.h"




int main(void){
	//All initializations
    init_RCC_APB2();
    init_RP();
    init_led_pin();
    init_extin();
		init_usart();	
	
	//Turn on led in PC13
		led_blink();
	
	//Request a string
		usart1_sendbyte('\n');
		usart1_sendstring("enter character:");  
		delay_ms(1000);

	
    while(1){
			clean_flag();
    }
}