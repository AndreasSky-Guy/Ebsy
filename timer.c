
 //////////////////////////////
 // SOURCE FILE  timer.c       //
 //////////////////////////////


/**************************************************************************
 *  Eingebettete Betriebssysteme (EBSy)		                                *  
 *                                                                        *
 **************************************************************************
 *  PROJECT       P1                                                      *
 *  MODULE        timer                                                   *
 *  REVISION      1.0                                                     *
 *  AUTHOR        Müller Dominik                                          *
 **************************************************************************
 *  PURPOSE:                                                              *
 *  Various functions to initialize timers																*
 *   						                                                          *
 *                                                                        *
 *                                                                        *
 **************************************************************************
 *  CHANGE HISTORY:                                                       *
 *   Revision  Date         Author            Description      					  *
 *     1.0    19.10.2020   Müller Dominik     creation                    *
 *                                                                        *
 *************************************************************************/


/* ---------------- G L O B A L   D E F I N I T I O N S ---------------- */

/*  - I n c l u d e s                                                    */

#include <stdint.h>
#include <LPC177x_8x.h>
#include "timer.h"
#include "LED.h"

/* ----------------- G L O B A L    V A R I A B L E S ------------------ */



/* ------------  F U N C T I O N   D E F I N I T I O N ----------------- */

/*  FUNCTION <timer_init>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    Initialization of Timers               															    *
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *    Timer, prescale Value                                                   *
 *                                                                            *
 ******************************************************************************
 *  RETURN VALUE                                                              *
 *      none                                                                  *
 *                                                                            *
 ******************************************************************************
 *  CHANGE HISTORY:                                                           *
 *   Revision   Date          Author      			Description                   *
 *      0        19.10.2020    Müller Dominik     creation                    *
 *                                                                            *
 ******************************************************************************/
void timer_init(int timer, int prescaleValue)
{
	LPC_SC->PCONP |= (1<<timer);						//enable power for chosen timer
	switch(timer){													//decide which timer to activate, set prescaler
		case TIMER0:
			LPC_TIM0->TCR = 1<<0;
			LPC_TIM0->PR = prescaleValue;
			LPC_TIM0->MR0 =100;
			LPC_TIM0->MCR |=(1<<1);
			break;
		case TIMER1:
			LPC_TIM1->TCR = 1<<0;
			LPC_TIM1->PR = prescaleValue;
			break;
		case TIMER2:
			LPC_TIM2->TCR = 1<<0;
			LPC_TIM2->PR = prescaleValue;
			break;
		case TIMER3:
			LPC_TIM3->TCR = 1<<0;
			LPC_TIM3->PR = prescaleValue;
			break;
		default: 
			break;
		
	}
}

void timer_systick_init(int prescaleValue)
{
	//NVIC_EnableIRQ(SysTick_IRQn);
	SysTick->LOAD = (40000 *prescaleValue)-1;
	SysTick->CTRL |= (1<<0);  //enable
	SysTick->CTRL |= (1<<1);	//interrupt enable
	SysTick->CTRL |= (1<<2);  //use internal clock
	
}




