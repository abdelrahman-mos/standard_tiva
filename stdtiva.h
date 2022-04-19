//***********************************************************//
//
// stdtiva.h - standard functions header for tiva TM4C123GH6PM
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

#ifndef STDTIVA_H
#define STDTIVA_H
#include "tm4c123gh6pm.h"
#include <stdint.h>

//***********************************************************//
//
// pins enum as their numbers defined in the datasheet of TM4C123GH6PM
//
//***********************************************************//
typedef enum {
	PA0 = 17,
	PA1 = 18,
	PA2 = 19,
	PA3 = 20,
	PA4 = 21,
	PA5 = 22,
	PA6 = 23,
	PA7 = 24,
	PB0 = 45,
	PB1 = 46,
	PB2 = 47,
	PB3 = 48,
	PB4 = 58,
	PB5 = 57,
	PB6 = 1,
	PB7 = 4,
	PC0 = 52,
	PC1 = 51,
	PC2 = 50,
	PC3 = 49,
	PC4 = 16,
	PC5 = 15,
	PC6 = 14,
	PC7 = 13,
	PD0 = 61,
	PD1 = 62,
	PD2 = 63,
	PD3 = 64,
	PD4 = 43,
	PD5 = 44,
	PD6 = 53,
	PD7 = 10,
	PE0 = 9,
	PE1 = 8,
	PE2 = 7,
	PE3 = 6,
	PE4 = 59,
	PE5 = 60,
	PF0 = 28,
	PF1 = 29,
	PF2 = 30,
	PF3 = 31,
	PF4 = 5
} Pin;

typedef enum {
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF
} PORT;

typedef enum { LOW = 0, HIGH = 1 } Digital;

typedef enum { INPUT, OUTPUT } Direction;


//***********************************************************//
//
// FUNCTIONS HANDLERS
//
//***********************************************************//
//***********************************************************//
//
// PORT F FUNCTIONS
//
//***********************************************************//
void PORTF_Init(void);			   			// initializes 
uint32_t PORTF_Input(void);		   	  // reads input from input pins in port F
void PORTF_Output(uint32_t data);   // writes output to output pins in port F

//***********************************************************//
//
// SYSTICK FUNCTIONS
//
//***********************************************************//
void SysTick_Init(void);					// must be called before using SysTick functions
void SysTick_Wait(uint32_t delay);			// to wait a certain delay calculated by the system timer
void SysTick_delay(uint32_t delayms);		// to wait a certain delay in ms
void SysTick_delayus(uint32_t delayus);		// to wait a certain delay in us
//***********************************************************//
//
// STANDARD FUNCTIONS
// these are the main purpose of this file
//
//***********************************************************//
void pinMode(Pin pin, Direction dir);
void digitalEnable(Pin pin, PORT port);
void digitalWrite(Pin pin, Digital I_O);

#endif //STDTIVA_H
