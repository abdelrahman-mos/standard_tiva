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

void digitalEnable(Pin pin, PORT port) {
	unsigned long mask = 0;
	switch (port)
	{
		case PORTA:
			if ((SYSCTL_PRGPIO_R & 0x00000001)==0)
				PORTA_Init();
			switch (pin) {
				case PA0: mask = 1;      break;
				case PA1: mask = (1<<1); break;
				case PA2: mask = (1<<2); break;
				case PA3: mask = (1<<3); break;
				case PA4: mask = (1<<4); break;
				case PA5: mask = (1<<5); break;
				case PA6: mask = (1<<6); break;
				case PA7: mask = (1<<7); break;
			}
			GPIO_PORTA_DEN_R |= mask;
			
			break;
			case PORTB:
			if ((SYSCTL_PRGPIO_R & 0x00000002)==0)
				PORTB_Init();
			switch (pin) {
				case PB0: mask = 1;      break;
				case PB1: mask = (1<<1); break;
				case PB2: mask = (1<<2); break;
				case PB3: mask = (1<<3); break;
				case PB4: mask = (1<<4); break;
				case PB5: mask = (1<<5); break;
				case PB6: mask = (1<<6); break;
				case PB7: mask = (1<<7); break;
			}
			GPIO_PORTB_DEN_R |= mask;
			
			break;
			case PORTD:
			if ((SYSCTL_PRGPIO_R & 0x00000008)==0)
				PORTD_Init();
			switch (pin) {
				case PD0: mask = 1;      break;
				case PD1: mask = (1<<1); break;
				case PD2: mask = (1<<2); break;
				case PD3: mask = (1<<3); break;
				case PD4: mask = (1<<4); break;
				case PD5: mask = (1<<5); break;
				case PD6: mask = (1<<6); break;
				case PD7: mask = (1<<7); break;
			}
			GPIO_PORTD_DEN_R |= mask;
			
			break;
			case PORTE:
			if ((SYSCTL_PRGPIO_R & 0x00000010)==0)
				PORTE_Init();
			switch (pin) {
				case PE0: mask = 1;      break;
				case PE1: mask = (1<<1); break;
				case PE2: mask = (1<<2); break;
				case PE3: mask = (1<<3); break;
				case PE4: mask = (1<<4); break;
				case PE5: mask = (1<<5); break;
			}
			GPIO_PORTE_DEN_R |= mask;
			
			break;
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
		case PA0:
			if ((SYSCTL_PRGPIO_R & 0x00000001)==0)
				PORTA_Init();
			if (dir == OUTPUT)
				GPIO_PORTA_DIR_R |= 1;
			else
				GPIO_PORTA_DIR_R &= ~1;
			break;
			case PA1:
			if ((SYSCTL_PRGPIO_R & 0x00000001)==0)
				PORTA_Init();
			if (dir == OUTPUT)
				GPIO_PORTA_DIR_R |= (1<<1);
			else
				GPIO_PORTA_DIR_R &= ~(1<<1);
			break;
			case PA2:
			if ((SYSCTL_PRGPIO_R & 0x00000001)==0)
				PORTA_Init();
			if (dir == OUTPUT)
				GPIO_PORTA_DIR_R |= (1<<2);
			else
				GPIO_PORTA_DIR_R &= ~(1<<2);
			break;
			case PA3:
			if ((SYSCTL_PRGPIO_R & 0x00000001)==0)
				PORTA_Init();
			if (dir == OUTPUT)
				GPIO_PORTA_DIR_R |= (1<<3);
			else
				GPIO_PORTA_DIR_R &= ~(1<<3);
			break;
			case PA4:
			if ((SYSCTL_PRGPIO_R & 0x00000001)==0)
				PORTA_Init();
			if (dir == OUTPUT)
				GPIO_PORTA_DIR_R |= (1<<4);
			else
				GPIO_PORTA_DIR_R &= ~(1<<4);
			break;
			case PA5:
			if ((SYSCTL_PRGPIO_R & 0x00000001)==0)
				PORTA_Init();
			if (dir == OUTPUT)
				GPIO_PORTA_DIR_R |= (1<<5);
			else
				GPIO_PORTA_DIR_R &= ~(1<<5);
			break;
			case PA6:
			if ((SYSCTL_PRGPIO_R & 0x00000001)==0)
				PORTA_Init();
			if (dir == OUTPUT)
				GPIO_PORTA_DIR_R |= (1<<6);
			else
				GPIO_PORTA_DIR_R &= ~(1<<6);
			break;
			case PA7:
			if ((SYSCTL_PRGPIO_R & 0x00000001)==0)
				PORTA_Init();
			if (dir == OUTPUT)
				GPIO_PORTA_DIR_R |= (1<<7);
			else
				GPIO_PORTA_DIR_R &= ~(1<<7);
			break;
			case PB0:
				if ((SYSCTL_PRGPIO_R & 0x00000002)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTB_DIR_R |= 1;
			else
				GPIO_PORTB_DIR_R &= ~1;
			break;
			case PB1:
				if ((SYSCTL_PRGPIO_R & 0x00000002)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTB_DIR_R |= (1<<1);
			else
				GPIO_PORTB_DIR_R &= ~(1<<1);
			break;
			case PB2:
				if ((SYSCTL_PRGPIO_R & 0x00000002)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTB_DIR_R |= (1<<2);
			else
				GPIO_PORTB_DIR_R &= ~(1<<2);
			break;
			case PB3:
				if ((SYSCTL_PRGPIO_R & 0x00000002)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTB_DIR_R |= (1<<3);
			else
				GPIO_PORTB_DIR_R &= ~(1<<3);
			break;
			case PB4:
				if ((SYSCTL_PRGPIO_R & 0x00000002)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTB_DIR_R |= (1<<4);
			else
				GPIO_PORTB_DIR_R &= ~(1<<4);
			break;
			case PB5:
				if ((SYSCTL_PRGPIO_R & 0x00000002)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTB_DIR_R |= (1<<5);
			else
				GPIO_PORTB_DIR_R &= ~(1<<5);
			break;
			case PB6:
				if ((SYSCTL_PRGPIO_R & 0x00000002)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTB_DIR_R |= (1<<6);
			else
				GPIO_PORTB_DIR_R &= ~(1<<6);
			break;
			case PB7:
				if ((SYSCTL_PRGPIO_R & 0x00000002)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTB_DIR_R |= (1<<7);
			else
				GPIO_PORTB_DIR_R &= ~(1<<7);
			break;
			case PD0:
				if ((SYSCTL_PRGPIO_R & 0x00000008)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTD_DIR_R |= 1;
			else
				GPIO_PORTD_DIR_R &= ~1;
			break;
			case PD1:
				if ((SYSCTL_PRGPIO_R & 0x00000008)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTD_DIR_R |= (1<<1);
			else
				GPIO_PORTD_DIR_R &= ~(1<<1);
			break;
			case PD2:
				if ((SYSCTL_PRGPIO_R & 0x00000008)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTD_DIR_R |= (1<<2);
			else
				GPIO_PORTD_DIR_R &= ~(1<<2);
			break;
			case PD3:
				if ((SYSCTL_PRGPIO_R & 0x00000008)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTD_DIR_R |= (1<<3);
			else
				GPIO_PORTD_DIR_R &= ~(1<<3);
			break;
			case PD4:
				if ((SYSCTL_PRGPIO_R & 0x00000008)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTD_DIR_R |= (1<<4);
			else
				GPIO_PORTD_DIR_R &= ~(1<<4);
			break;
			case PD5:
				if ((SYSCTL_PRGPIO_R & 0x00000008)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTD_DIR_R |= (1<<5);
			else
				GPIO_PORTD_DIR_R &= ~(1<<5);
			break;
			case PD6:
				if ((SYSCTL_PRGPIO_R & 0x00000008)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTD_DIR_R |= (1<<6);
			else
				GPIO_PORTD_DIR_R &= ~(1<<6);
			break;
			case PD7:
				if ((SYSCTL_PRGPIO_R & 0x00000008)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTD_DIR_R |= (1<<7);
			else
				GPIO_PORTD_DIR_R &= ~(1<<7);
			break;
			case PE0:
				if ((SYSCTL_PRGPIO_R & 0x00000010)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTE_DIR_R |= 1;
			else
				GPIO_PORTE_DIR_R &= ~1;
			break;
			case PE1:
				if ((SYSCTL_PRGPIO_R & 0x00000010)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTE_DIR_R |= (1<<1);
			else
				GPIO_PORTE_DIR_R &= ~(1<<1);
			break;
			case PE2:
				if ((SYSCTL_PRGPIO_R & 0x00000010)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTE_DIR_R |= (1<<2);
			else
				GPIO_PORTE_DIR_R &= ~(1<<2);
			break;
			case PE3:
				if ((SYSCTL_PRGPIO_R & 0x00000010)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTE_DIR_R |= (1<<3);
			else
				GPIO_PORTE_DIR_R &= ~(1<<3);
			break;
			case PE4:
				if ((SYSCTL_PRGPIO_R & 0x00000010)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTE_DIR_R |= (1<<4);
			else
				GPIO_PORTE_DIR_R &= ~(1<<4);
			break;
			case PE5:
				if ((SYSCTL_PRGPIO_R & 0x00000010)==0)
					PORTB_Init();
				if (dir == OUTPUT)
				GPIO_PORTE_DIR_R |= (1<<5);
			else
				GPIO_PORTE_DIR_R &= ~(1<<5);
			break;
		case PF0:
			if ((SYSCTL_PRGPIO_R & 0x00000020)==0)
				PORTF_Init();
			if (dir == OUTPUT)
				GPIO_PORTF_DIR_R |= 1;
			else
				GPIO_PORTF_DIR_R &= ~1;
			break;
		case PF1:
			if ((SYSCTL_PRGPIO_R & 0x00000020)==0)
				PORTF_Init();
			if (dir == OUTPUT)
				GPIO_PORTF_DIR_R |= (1<<1);
			else
				GPIO_PORTF_DIR_R &= ~(1<<1);
			break;
		case PF2:
			if ((SYSCTL_PRGPIO_R & 0x00000020)==0)
				PORTF_Init();
			if (dir == OUTPUT)
				GPIO_PORTF_DIR_R |= (1<<2);
			else
				GPIO_PORTF_DIR_R &= ~(1<<2);
			break;
		case PF3:
			if ((SYSCTL_PRGPIO_R & 0x00000020)==0)
				PORTF_Init();
			if (dir == OUTPUT)
				GPIO_PORTF_DIR_R |= (1<<3);
			else
				GPIO_PORTF_DIR_R &= ~(1<<3);
			break;
		case PF4:
			if ((SYSCTL_PRGPIO_R & 0x00000020)==0)
				PORTF_Init();
			if (dir == OUTPUT)
				GPIO_PORTF_DIR_R |= (1<<4);
			else
				GPIO_PORTF_DIR_R &= ~(1<<4);
			break;
	}
}

void digitalWrite(Pin pin, Digital I_O) {
	switch (pin) {
		case PA0:
			digitalEnable(PA0, PORTA);
			if (I_O == HIGH)
				GPIO_PORTA_DATA_R |= 1;
			else
				GPIO_PORTA_DATA_R &= ~1;
			break;
		case PA1:
			digitalEnable(PA1, PORTA);
			if (I_O == HIGH)
				GPIO_PORTA_DATA_R |= (1<<1);
			else
				GPIO_PORTA_DATA_R &= ~(1<<1);
			break;
		case PA2:
			digitalEnable(PA2, PORTA);
			if (I_O == HIGH)
				GPIO_PORTA_DATA_R |= (1<<2);
			else
				GPIO_PORTA_DATA_R &= ~(1<<2);
			break;
		case PA3:
			digitalEnable(PA3, PORTA);
			if (I_O == HIGH)
				GPIO_PORTA_DATA_R |= (1<<3);
			else
				GPIO_PORTA_DATA_R &= ~(1<<3);
			break;
		case PA4:
			digitalEnable(PA4, PORTA);
			if (I_O == HIGH)
				GPIO_PORTA_DATA_R |= (1<<4);
			else
				GPIO_PORTA_DATA_R &= ~(1<<4);
			break;
		case PA5:
			digitalEnable(PA5, PORTA);
			if (I_O == HIGH)
				GPIO_PORTA_DATA_R |= (1<<5);
			else
				GPIO_PORTA_DATA_R &= ~(1<<5);
			break;
		case PA6:
			digitalEnable(PA6, PORTA);
			if (I_O == HIGH)
				GPIO_PORTA_DATA_R |= (1<<6);
			else
				GPIO_PORTA_DATA_R &= ~(1<<6);
			break;
		case PA7:
			digitalEnable(PA7, PORTA);
			if (I_O == HIGH)
				GPIO_PORTA_DATA_R |= (1<<7);
			else
				GPIO_PORTA_DATA_R &= ~(1<<7);
			break;
		case PB0:
			digitalEnable(PB0, PORTB);
			if (I_O == HIGH)
				GPIO_PORTB_DATA_R |= 1;
			else
				GPIO_PORTB_DATA_R &= ~1;
			break;
		case PB1:
			digitalEnable(PB1, PORTB);
			if (I_O == HIGH)
				GPIO_PORTB_DATA_R |= (1<<1);
			else
				GPIO_PORTB_DATA_R &= ~(1<<1);
			break;
		case PB2:
			digitalEnable(PB2, PORTB);
			if (I_O == HIGH)
				GPIO_PORTB_DATA_R |= (1<<2);
			else
				GPIO_PORTB_DATA_R &= ~(1<<2);
			break;
		case PB3:
			digitalEnable(PB3, PORTB);
			if (I_O == HIGH)
				GPIO_PORTB_DATA_R |= (1<<3);
			else
				GPIO_PORTB_DATA_R &= ~(1<<3);
			break;
		case PB4:
			digitalEnable(PB4, PORTB);
			if (I_O == HIGH)
				GPIO_PORTB_DATA_R |= (1<<4);
			else
				GPIO_PORTB_DATA_R &= ~(1<<4);
			break;
		case PB5:
			digitalEnable(PB5, PORTB);
			if (I_O == HIGH)
				GPIO_PORTB_DATA_R |= (1<<5);
			else
				GPIO_PORTB_DATA_R &= ~(1<<5);
			break;
		case PB6:
			digitalEnable(PB6, PORTB);
			if (I_O == HIGH)
				GPIO_PORTB_DATA_R |= (1<<6);
			else
				GPIO_PORTB_DATA_R &= ~(1<<6);
			break;
		case PB7:
			digitalEnable(PB7, PORTB);
			if (I_O == HIGH)
				GPIO_PORTB_DATA_R |= (1<<7);
			else
				GPIO_PORTB_DATA_R &= ~(1<<7);
			break;
		case PD0:
			digitalEnable(PD0, PORTD);
			if (I_O == HIGH)
				GPIO_PORTD_DATA_R |= 1;
			else
				GPIO_PORTD_DATA_R &= ~1;
			break;
		case PD1:
			digitalEnable(PD1, PORTD);
			if (I_O == HIGH)
				GPIO_PORTD_DATA_R |= (1<<1);
			else
				GPIO_PORTD_DATA_R &= ~(1<<1);
			break;
		case PD2:
			digitalEnable(PD2, PORTD);
			if (I_O == HIGH)
				GPIO_PORTD_DATA_R |= (1<<2);
			else
				GPIO_PORTD_DATA_R &= ~(1<<2);
			break;
		case PD3:
			digitalEnable(PD3, PORTD);
			if (I_O == HIGH)
				GPIO_PORTD_DATA_R |= (1<<3);
			else
				GPIO_PORTD_DATA_R &= ~(1<<3);
			break;
		case PD4:
			digitalEnable(PD4, PORTD);
			if (I_O == HIGH)
				GPIO_PORTD_DATA_R |= (1<<4);
			else
				GPIO_PORTD_DATA_R &= ~(1<<4);
			break;
		case PD5:
			digitalEnable(PD5, PORTD);
			if (I_O == HIGH)
				GPIO_PORTD_DATA_R |= (1<<5);
			else
				GPIO_PORTD_DATA_R &= ~(1<<5);
			break;
		case PD6:
			digitalEnable(PD6, PORTD);
			if (I_O == HIGH)
				GPIO_PORTD_DATA_R |= (1<<6);
			else
				GPIO_PORTD_DATA_R &= ~(1<<6);
			break;
		case PD7:
			digitalEnable(PD7, PORTD);
			if (I_O == HIGH)
				GPIO_PORTD_DATA_R |= (1<<7);
			else
				GPIO_PORTD_DATA_R &= ~(1<<7);
			break;
		case PE0:
			digitalEnable(PE0, PORTE);
			if (I_O == HIGH)
				GPIO_PORTE_DATA_R |= 1;
			else
				GPIO_PORTE_DATA_R &= ~1;
			break;
		case PE1:
			digitalEnable(PE1, PORTE);
			if (I_O == HIGH)
				GPIO_PORTE_DATA_R |= (1<<1);
			else
				GPIO_PORTE_DATA_R &= ~(1<<1);
			break;
		case PE2:
			digitalEnable(PE2, PORTE);
			if (I_O == HIGH)
				GPIO_PORTE_DATA_R |= (1<<2);
			else
				GPIO_PORTE_DATA_R &= ~(1<<2);
			break;
		case PE3:
			digitalEnable(PE3, PORTE);
			if (I_O == HIGH)
				GPIO_PORTE_DATA_R |= (1<<3);
			else
				GPIO_PORTE_DATA_R &= ~(1<<3);
			break;
		case PE4:
			digitalEnable(PE4, PORTE);
			if (I_O == HIGH)
				GPIO_PORTE_DATA_R |= (1<<4);
			else
				GPIO_PORTE_DATA_R &= ~(1<<4);
			break;
		case PE5:
			digitalEnable(PE5, PORTE);
			if (I_O == HIGH)
				GPIO_PORTE_DATA_R |= (1<<5);
			else
				GPIO_PORTE_DATA_R &= ~(1<<5);
			break;
		case PF0:
			digitalEnable(PF0, PORTF);
			if (I_O == HIGH)
				GPIO_PORTF_DATA_R |= 1;
			else
				GPIO_PORTF_DATA_R &= ~1;
			break;
		case PF1:
			digitalEnable(PF1, PORTF);
			if (I_O == HIGH)
				GPIO_PORTF_DATA_R |= (1<<1);
			else
				GPIO_PORTF_DATA_R &= ~(1<<1);
			break;
		case PF2:
			digitalEnable(PF2, PORTF);
			if (I_O == HIGH)
				GPIO_PORTF_DATA_R |= (1<<2);
			else
				GPIO_PORTF_DATA_R &= ~(1<<2);
			break;
		case PF3:
			digitalEnable(PF3, PORTF);
			if (I_O == HIGH)
				GPIO_PORTF_DATA_R |= (1<<3);
			else
				GPIO_PORTF_DATA_R &= ~(1<<3);
			break;
		case PF4:
			digitalEnable(PF4, PORTF);
			if (I_O == HIGH)
				GPIO_PORTF_DATA_R |= (1<<4);
			else
				GPIO_PORTF_DATA_R &= ~(1<<4);
			break;
	}
}
