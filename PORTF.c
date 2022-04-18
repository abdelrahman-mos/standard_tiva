#include "stdtiva.h"

void PORTF_Init(void) {
	SYSCTL_RCGCGPIO_R |= 0x00000020;
	while ((SYSCTL_PRGPIO_R & 0x00000020)==0) {}
	GPIO_PORTF_LOCK_R  = 0x4C4F434B; //unlock GPIO port F
	GPIO_PORTF_CR_R    = 0x1F;			 //allow changes to port F
	GPIO_PORTF_AFSEL_R = 0x00;			 //disable alt function on PF7-0
}

uint32_t PORTF_Input(void) {
	// Will return the values which are set to input 
	// (at which DIR = 0)
	return (GPIO_PORTF_DATA_R & ~(GPIO_PORTF_DIR_R));
}

void PORTF_Output(uint32_t data) {
	// Will write data to pins set as output pins
	GPIO_PORTF_DATA_R = data;
}