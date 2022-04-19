#include "stdtiva.h"

void PORTE_Init(void) {
	SYSCTL_RCGCGPIO_R |= 0x00000010;
	while ((SYSCTL_PRGPIO_R & 0x00000010)==0) {}
	GPIO_PORTE_LOCK_R  = 0x4C4F434B; //unlock GPIO port F
	GPIO_PORTE_CR_R    = 0x1F;			 //allow changes to port F
	GPIO_PORTE_AFSEL_R = 0x00;			 //disable alt function on PF7-0
}

uint32_t PORTE_Input(void) {
	// Will return the values which are set to input 
	// (at which DIR = 0)
	return (GPIO_PORTE_DATA_R & ~(GPIO_PORTE_DIR_R));
}

void PORTE_Output(uint32_t data) {
	// Will write data to pins set as output pins
	GPIO_PORTE_DATA_R = data;
}
