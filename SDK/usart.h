#ifndef _USART
#define _USART
#include <stm32f10x.h>

void usart1_sendbyte(unsigned char c);
void usart1_sendstring(char s[]);
uint8_t usart1_receivebyte();

#endif
