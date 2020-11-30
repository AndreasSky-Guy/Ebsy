
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
	Sys_Init();
	LED_init();
	timer_init(TIMER0,3000);
	timer_init(TIMER1,30000);
	
	//create process LED lauf1
	//create process warte
	//create process LED lauf2
	while(1)
	{
		Sys_Task_Scheduler();
	}
}

