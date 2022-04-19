#include "stdtiva.h"

void SysTick_Init(void) {
	NVIC_ST_CTRL_R    = 0;					//disable counter
	NVIC_ST_RELOAD_R  = 0x00FFFFFF; //setting maaximum value of reload
	NVIC_ST_CURRENT_R = 0;					//resetting current
	NVIC_ST_CTRL_R    = 0x00000005; //enabling the counter
	// CTRL set to 0101 (CLK_SRC => SYSTEM CLOCK, INTERRUBT => 0,ENABLE => 1)
}

void SysTick_Wait(uint32_t delay) {
	NVIC_ST_RELOAD_R = delay - 1;
	NVIC_ST_CURRENT_R = 0;
	while ((NVIC_ST_CTRL_R&0x00010000)==0) {}
			//keep looping while bit 16 toggles (counter reaches 0)
}



void SysTick_delay(uint32_t delay) {
	unsigned long i;
	for (i = 0; i < delay; i++)
		SysTick_Wait(8000);
}

void SysTick_delayus(uint32_t delayus) {
	unsigned long i;
	for (i = 0; i < delayus; i++)
		SysTick_Wait(8);
}
