#include <stm32f10x.h>
	
void usart1_sendbyte(unsigned char c){
	USART1->DR = c;
	while((USART1->SR&(1<<6))==0); 									//while not transmitted
	USART1->SR &= ~(1<<6); 													//reset for a new transmision
}
void usart1_sendstring(char s[]){
	int i = 0;
  while (i < 64){
	  if (s[i] == '\0') break;
	  usart1_sendbyte(s[i++]);
  }
}

uint8_t usart1_receivebyte(){
	while((USART1->SR & (1 << 5)) == 0);						//while data not received
	return USART1->DR;
}