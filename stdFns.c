#include "stdtiva.h"

void digitalEnable(Pin pin, PORT port) {
	unsigned long mask = 0;
	switch (port)
	{
		case PORTF:
			if ((SYSCTL_PRGPIO_R & 0x00000020)==0)
				PORTF_Init();
			switch (pin) {
				case PF0: mask = 1;      break;
				case PF1: mask = (1<<1); break;
				case PF2: mask = (1<<2); break;
				case PF3: mask = (1<<3); break;
				case PF4: mask = (1<<4); break;
			}
			GPIO_PORTF_DEN_R |= mask;
			
			break;
	}
}

void digitalWrite(Pin pin, digital I_O) {
	switch (pin) {
		case PF0:
			GPIO_PORTF_DIR_R |= 1;
			digitalEnable(PF0, PORTF);
			if (I_O)
				GPIO_PORTF_DATA_R |= 1;
			else
				GPIO_PORTF_DATA_R &= ~1;
			break;
		case PF1:
			GPIO_PORTF_DIR_R |= (1<<1);
			digitalEnable(PF1, PORTF);
			if (I_O)
				GPIO_PORTF_DATA_R |= (1<<1);
			else
				GPIO_PORTF_DATA_R &= ~(1<<1);
			break;
		case PF2:
			GPIO_PORTF_DIR_R |= (1<<2);
			digitalEnable(PF2, PORTF);
			if (I_O)
				GPIO_PORTF_DATA_R |= (1<<2);
			else
				GPIO_PORTF_DATA_R &= ~(1<<2);
			break;
		case PF3:
			GPIO_PORTF_DIR_R |= (1<<3);
			digitalEnable(PF3, PORTF);
			if (I_O)
				GPIO_PORTF_DATA_R |= (1<<3);
			else
				GPIO_PORTF_DATA_R &= ~(1<<3);
			break;
		case PF4:
			GPIO_PORTF_DIR_R |= (1<<4);
			digitalEnable(PF4, PORTF);
			if (I_O)
				GPIO_PORTF_DATA_R |= (1<<4);
			else
				GPIO_PORTF_DATA_R &= ~(1<<4);
			break;
	}
}
