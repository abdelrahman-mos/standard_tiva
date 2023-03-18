//***********************************************************//
//
// stdFns.c - standard functions for tiva TM4C123GH6PM
//
//***********************************************************//
//
// this software standarizes some functions for TM4C123GH6PM 
// tiva ware for the ease of use and learning
//
//***********************************************************//
//
// AUTHOR : Abderlahman Mostafa
// E-mail : boboelahlawy1234@hotmail.com
// for any questions and inquiries, please send an e-mail or 
// make it as a github pull request
//
//***********************************************************//
//
// THIS WAS MADE WHILE LEARNING THE INTRODUCTION TO EMBEDDED
// SYSTEMS COURSE AT FACULTY OF ENGINEERING, AIN SHAMS UNIVERSITY
//
//***********************************************************//

#include "stdtiva.h"

uint32_t mask(Pin pin) {
	uint32_t n;
	
	switch (pin) {
		case PA0:
		case PB0:
		case PD0:
		case PE0:
		case PF0:
			n = 0;
			break;
		case PA1:
		case PB1:
		case PD1:
		case PE1:
		case PF1:
			n = 1;
			break;
		case PA2:
		case PB2:
		case PD2:
		case PE2:
		case PF2:
			n = 2;
			break;
		case PA3:
		case PB3:
		case PD3:
		case PE3:
		case PF3:
			n = 3;
			break;
		case PA4:
		case PB4:
		case PD4:
		case PE4:
		case PF4:
			n = 4;
			break;
		case PA5:
		case PB5:
		case PD5:
		case PE5:
			n = 5;
			break;
		case PA6:
		case PB6:
		case PD6:
			n = 6;
			break;
		case PA7:
		case PB7:
		case PD7:
			n = 7;
			break;
	}
	
	return n;
}

void digitalEnable(Pin pin, PORT port) {
	
	uint32_t n = mask(pin);
	
	switch (port) {
		case PORTA:
			if ((SYSCTL_PRGPIO_R & 0x00000001)==0)
				PORTA_Init();
			GPIO_PORTA_DEN_R |= (1<<n);
			break;
		case PORTB:
			if ((SYSCTL_PRGPIO_R & 0x00000002)==0)
				PORTB_Init();
			GPIO_PORTB_DEN_R |= (1<<n);
			break;
		case PORTD:
			if ((SYSCTL_PRGPIO_R & 0x00000008)==0)
				PORTD_Init();
			GPIO_PORTD_DEN_R |= (1<<n);
			break;
		case PORTE:
			if ((SYSCTL_PRGPIO_R & 0x00000010)==0)
				PORTE_Init();
			GPIO_PORTE_DEN_R |= (1<<n);
			break;
		case PORTF:
			if ((SYSCTL_PRGPIO_R & 0x00000020)==0)
				PORTF_Init();
			GPIO_PORTF_DEN_R |= (1<<n);
			break;
	}
}

void pinMode(Pin pin, Direction dir) {
	
	uint32_t n = mask(pin);
	
	switch (pin) {
		case PA0:
		case PA1:
		case PA2:
		case PA3:
		case PA4:
		case PA5:
		case PA6:
		case PA7:
			if ((SYSCTL_PRGPIO_R & 0x00000001)==0)
				PORTA_Init();
			if (dir == OUTPUT)
				GPIO_PORTA_DIR_R |= (1<<n);
			else
				GPIO_PORTA_DIR_R &= ~(1<<n);
			break;
		case PB0:
		case PB1:
		case PB2:
		case PB3:
		case PB4:
		case PB5:
		case PB6:
		case PB7:
			if ((SYSCTL_PRGPIO_R & 0x00000002)==0)
				PORTB_Init();
			if (dir == OUTPUT)
				GPIO_PORTB_DIR_R |= (1<<n);
			else
				GPIO_PORTB_DIR_R &= ~(1<<n);
			break;
		case PD0:
		case PD1:
		case PD2:
		case PD3:
		case PD4:
		case PD5:
		case PD6:
		case PD7:
			if ((SYSCTL_PRGPIO_R & 0x00000008)==0)
				PORTB_Init();
			if (dir == OUTPUT)
				GPIO_PORTD_DIR_R |= (1<<n);
			else
				GPIO_PORTD_DIR_R &= ~(1<<n);
			break;
		case PE0:
		case PE1:
		case PE2:
		case PE3:
		case PE4:
		case PE5:
			if ((SYSCTL_PRGPIO_R & 0x00000010)==0)
				PORTB_Init();
			if (dir == OUTPUT)
				GPIO_PORTE_DIR_R |= (1<<n);
			else
				GPIO_PORTE_DIR_R &= ~(1<<n);
			break;
		case PF0:
		case PF1:
		case PF2:
		case PF3:
		case PF4:
			if ((SYSCTL_PRGPIO_R & 0x00000020)==0)
				PORTF_Init();
			if (dir == OUTPUT)
				GPIO_PORTF_DIR_R |= (1<<n);
			else
				GPIO_PORTF_DIR_R &= ~(1<<n);
			break;
	}
}

void digitalWrite(Pin pin, Digital I_O) {
	
	uint32_t n = mask(pin);
	
	switch (pin) {
		case PA0:
		case PA1:
		case PA2:
		case PA3:
		case PA4:
		case PA5:
		case PA6:
		case PA7:
			digitalEnable(pin, PORTA);
			if (I_O == HIGH)
				GPIO_PORTA_DATA_R |= (1<<n);
			else
				GPIO_PORTA_DATA_R &= ~(1<<n);
			break;
		case PB0:
		case PB1:
		case PB2:
		case PB3:
		case PB4:
		case PB5:
		case PB6:
		case PB7:
			digitalEnable(pin, PORTB);
			if (I_O == HIGH)
				GPIO_PORTB_DATA_R |= (1<<n);
			else
				GPIO_PORTB_DATA_R &= ~(1<<n);
			break;
		case PD0:
		case PD1:
		case PD2:
		case PD3:
		case PD4:
		case PD5:
		case PD6:
		case PD7:
			digitalEnable(pin, PORTD);
			if (I_O == HIGH)
				GPIO_PORTD_DATA_R |= (1<<n);
			else
				GPIO_PORTD_DATA_R &= ~(1<<n);
			break;
		case PE0:
		case PE1:
		case PE2:
		case PE3:
		case PE4:
		case PE5:
			digitalEnable(pin, PORTE);
			if (I_O == HIGH)
				GPIO_PORTE_DATA_R |= (1<<n);
			else
				GPIO_PORTE_DATA_R &= ~(1<<n);
			break;
		case PF0:
		case PF1:
		case PF2:
		case PF3:
		case PF4:
			digitalEnable(pin, PORTF);
			if (I_O == HIGH)
				GPIO_PORTF_DATA_R |= (1<<n);
			else
				GPIO_PORTF_DATA_R &= ~(1<<n);
			break;
	}
}

uint32_t digitalRead(Pin pin) {
	
	uint32_t n = mask(pin);
	
	switch (pin) {
		case PA0:
		case PA1:
		case PA2:
		case PA3:
		case PA4:
		case PA5:
		case PA6:
		case PA7:
			return (GPIO_PORTA_DATA_R>>n) & 0x01;
			break;
		case PB0:
		case PB1:
		case PB2:
		case PB3:
		case PB4:
		case PB5:
		case PB6:
		case PB7:
			return (GPIO_PORTB_DATA_R>>n) & 0x01;
		break;
		case PD0:
		case PD1:
		case PD2:
		case PD3:
		case PD4:
		case PD5:
		case PD6:
		case PD7:
			return (GPIO_PORTD_DATA_R>>n) & 0x01;
		break;
		case PE0:
		case PE1:
		case PE2:
		case PE3:
		case PE4:
		case PE5:
			return (GPIO_PORTE_DATA_R>>n) & 0x01;
		break;
		case PF0:
		case PF1:
		case PF2:
		case PF3:
		case PF4:
			return (GPIO_PORTF_DATA_R>>n) & 0x01;
		break;
	}
}
