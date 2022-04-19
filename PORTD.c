#include "stdtiva.h"

void PORTD_Init(void) {
	SYSCTL_RCGCGPIO_R |= 0x00000008;
	while ((SYSCTL_PRGPIO_R & 0x00000008)==0) {}
	GPIO_PORTA_LOCK_R  = 0x4C4F434B; //unlock GPIO port F
	GPIO_PORTA_CR_R    = 0x7F;			 //allow changes to port F
	GPIO_PORTA_AFSEL_R = 0x00;			 //disable alt function on PF7-0
}

uint32_t PORTD_Input(void) {
	// Will return the values which are set to input 
	// (at which DIR = 0)
	return (GPIO_PORTD_DATA_R & ~(GPIO_PORTD_DIR_R));
}

void PORTD_Output(uint32_t data) {
	// Will write data to pins set as output pins
	GPIO_PORTD_DATA_R = data;
}
