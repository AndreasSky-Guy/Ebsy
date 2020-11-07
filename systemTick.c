#include <stdint.h>
#include <LPC177x_8x.h>
#include "systemTick.h"

volatile uint32_t msTicks = 0;                              /* Variable to store millisecond ticks */
  
void SysTick_Handler(void)  {                               /* SysTick interrupt Handler. */
  msTicks++;                                                /* See startup file startup_LPC17xx.s for SysTick vector */ 
}

void SysTick_Init()
{
	SysTick_Config(30000); // =1ms
}

uint32_t Timer_GetSystemTick()
{
	return msTicks;
}
