#include "leds.h"
#include "exti.h"
#include "USART.h"
#include "delay.h"

uint8_t receivedbyte;

int main(){
	init_led_pin();
	led_on_off();
	init_exti_pin();
	init_exti();
	usart_ini();
	
	usart1_sendbyte('\n');
	usart1_sendstring("enter character:");  
	delay_ms(1000);

	while(1){
		receivedbyte = usart1_receivebyte();
		usart1_sendbyte(receivedbyte);    
	}
}
