#include "stdtiva.h"

void PORTB_Init(void) {
	SYSCTL_RCGCGPIO_R |= 0x00000002;
	while ((SYSCTL_PRGPIO_R & 0x00000002)==0) {}
	GPIO_PORTB_LOCK_R  = 0x4C4F434B; //unlock GPIO port F
	GPIO_PORTB_CR_R    = 0x7F;			 //allow changes to port F
	GPIO_PORTB_AFSEL_R = 0x00;			 //disable alt function on PF7-0
}

uint32_t PORTB_Input(void) {
	// Will return the values which are set to input 
	// (at which DIR = 0)
	return (GPIO_PORTB_DATA_R & ~(GPIO_PORTB_DIR_R));
}

void PORTB_Output(uint32_t data) {
	// Will write data to pins set as output pins
	GPIO_PORTB_DATA_R = data;
}
