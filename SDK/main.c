//Karla Yammilet Martinez Pichal
//Luis Elias Valle Velázquez
//Galilea Yamile Sanchez Andrade
//José Emmanuel Castro Velázquez


#include	<stm32f10x.h>
#include "leds.h"
#include "GPIOS1.h"
#include "extin.h"


int main(void){
    BC_enb();
    init_RP();
    init_led_pin();
    init_extin();
		GPIOC->ODR |= (1 << 13);
	
    while(1){
    }
}