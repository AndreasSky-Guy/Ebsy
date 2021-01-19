
 //////////////////////////////
 // SOURCE FILE  main.c       //
 //////////////////////////////


/**************************************************************************
 *  Eingebettete Betriebssysteme (EBSy)		                                *  
 *                                                                        *
 **************************************************************************
 *  PROJECT       P1                                                      *
 *  MODULE        main.c                                                  *
 *  REVISION      1.0                                                     *
 *  AUTHOR        Müller Dominik                                          *
 **************************************************************************
 *  PURPOSE:                                                              *
 *  main loop												 																			*
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
#include "LED.h"
#include "timer.h"
#include "ProcessHandler.h"


extern pcb_type processTable[NPROCS];

int main(void)
{
	
	LED_init();
	timer_init(TIMER1,30000); // 1 ms
	
	createProcess(&LED_run1, ready);
	//createProcess(&LED_wait, ready);
	createProcess(&LED_run2, ready);
	//first_context(&processTable[0].sp);
	timer_systick_init(1);								//enable system interrupt every 1ms
	
	while(1)
	{
	}
}

