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

void pinMode(Pin pin, Direction dir) {
	switch (pin) {
		case PF0:
			if ((SYSCTL_PRGPIO_R & 0x00000020)==0)
				PORTF_Init();
			if (dir == OUTPUT)
				GPIO_PORTF_DIR_R |= 1;
			else
				GPIO_PORTF_DIR_R &= ~1;
		case PF1:
			if ((SYSCTL_PRGPIO_R & 0x00000020)==0)
				PORTF_Init();
			if (dir == OUTPUT)
				GPIO_PORTF_DIR_R |= (1<<1);
			else
				GPIO_PORTF_DIR_R &= ~(1<<1);
		case PF2:
			if ((SYSCTL_PRGPIO_R & 0x00000020)==0)
				PORTF_Init();
			if (dir == OUTPUT)
				GPIO_PORTF_DIR_R |= (1<<2);
			else
				GPIO_PORTF_DIR_R &= ~(1<<2);
		case PF3:
			if ((SYSCTL_PRGPIO_R & 0x00000020)==0)
				PORTF_Init();
			if (dir == OUTPUT)
				GPIO_PORTF_DIR_R |= (1<<3);
			else
				GPIO_PORTF_DIR_R &= ~(1<<3);
		case PF4:
			if ((SYSCTL_PRGPIO_R & 0x00000020)==0)
				PORTF_Init();
			if (dir == OUTPUT)
				GPIO_PORTF_DIR_R |= (1<<4);
			else
				GPIO_PORTF_DIR_R &= ~(1<<4);
	}
}

void digitalWrite(Pin pin, Digital I_O) {
	switch (pin) {
		case PF0:
			digitalEnable(PF0, PORTF);
			if (I_O == HIGH)
				GPIO_PORTF_DATA_R |= 0x00000001;
			else
				GPIO_PORTF_DATA_R &= !(0x00000001);
			break;
		case PF1:
			digitalEnable(PF1, PORTF);
			if (I_O == HIGH)
				GPIO_PORTF_DATA_R |= (0x00000001<<1);
			else
				GPIO_PORTF_DATA_R &= !(0x00000001<<1);
			break;
		case PF2:
			digitalEnable(PF2, PORTF);
			if (I_O == HIGH)
				GPIO_PORTF_DATA_R |= (0x00000001<<2);
			else
				GPIO_PORTF_DATA_R &= !(0x00000001<<2);
			break;
		case PF3:
			digitalEnable(PF3, PORTF);
			if (I_O == HIGH)
				GPIO_PORTF_DATA_R |= (0x00000001<<3);
			else
				GPIO_PORTF_DATA_R &= ~(0x08);
			break;
		case PF4:
			digitalEnable(PF4, PORTF);
			if (I_O == HIGH)
				GPIO_PORTF_DATA_R |= (0x00000001<<4);
			else
				GPIO_PORTF_DATA_R &= !(0x00000001<<4);
			break;
	}
}
