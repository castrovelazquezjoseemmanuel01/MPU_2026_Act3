#include "leds.h"

int main(){
		init_gpioc();

	while(1){
		led_on_off();	
	}
}