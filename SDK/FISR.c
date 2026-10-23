//Functions for flag interrupt serviece routine

#include <stm32f10x.h>
#include "times.h"
#include "usart.h"

// Blink LED three times
void led_blink(void){
    for(int x = 0; x < 3; x++){
        GPIOC->ODR |= (1 << 13);
				delay_ms(100);
				GPIOC->ODR &= ~(1 << 13);
        delay_ms(100);
    }
}
volatile uint8_t contador = 1;
void extin_count(void){
	
    //Print "No. Interrupciones" with line jump
    usart1_sendstring("\r\n");
		usart1_sendstring("No. Interrupciones:");
	
    //Convert the integer value to ASCII (byte by byte)
    
	
		if(contador < 10){													//From 0 to 9
        usart1_sendbyte(contador + '0');
    } else {																		//From 10 to 15
        usart1_sendbyte('1');                   
        usart1_sendbyte((contador - 10) + '0'); 
    }
    
    usart1_sendstring("\r\n");
    
    //Inc counter
    contador++;
		
		//Reset counter
    if(contador > 15){
        contador = 0;
    }
		
}
