#include "stdtiva.h"

void PORTF_Init(void) {
	SYSCTL_RCGCGPIO_R |= 0x00000020;
	while ((SYSCTL_PRGPIO_R & 0x00000020)==0) {}
}
