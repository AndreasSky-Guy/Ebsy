//////////////////////////////
 // SOURCE FILE  main.c       //
 //////////////////////////////


/**************************************************************************
 *  Eingebettete Betriebssysteme (EBSy)		                                *  
 *                                                                        *
 **************************************************************************
 *  PROJECT       P1                                                      *
 *  MODULE        eventHandler.c                                          *
 *  REVISION      1.0                                                     *
 *  AUTHOR        M�ller Dominik                                          *
 **************************************************************************
 *  PURPOSE:                                                              *
 *  handles events  								 																			*
 *   						                                                          *
 *                                                                        *
 *                                                                        *
 **************************************************************************
 *  CHANGE HISTORY:                                                       *
 *   Revision  Date         Author            Description      					  *
 *     1.0    02.11.2020   M�ller Dominik     creation                    *
 *                                                                        *
 *************************************************************************/


/* ---------------- G L O B A L   D E F I N I T I O N S ---------------- */

/*  - I n c l u d e s                                                    */
#include <stdint.h>
#include <LPC177x_8x.h>
#include "eventHandler.h"
#include "LED.h"
#include "systemTick.h"


static TaskType Tasks[] = {
{ 0,              0, Tsk        },
{ INTERVAL_10ms,  0, Tsk_10ms   },
{ INTERVAL_50ms,  0, Tsk_50ms   },
{ INTERVAL_100ms, 0, Tsk_100ms  },
};


static uint32_t tick = 0;          //   System�tick�: aktuelle Zeit
static TaskType *TaskPtr = Tasks;  // Zeiger auf Prozesstabelle
static uint8_t  TaskIdx = 0;       // Aktueller Task (�Index�)
const uint8_t  NumTasks = sizeof(Tasks) / sizeof(*Tasks);  // Anzahl Tasks


void Sys_Init()
{
	createProcess(1, LED_on);
	
	
}

pid_t createProcess(int id, uint32_t (*func)(uint8_t a))
{
	pcb_type process;
	process.id = 1;
	process.func = func;
	
	processTable[0] = process;
}



void handle()
{
	tick = Timer_GetSystemTick();    // aktuelle Zeit ermitteln
	for(TaskIdx= 0; TaskIdx < NumTasks; TaskIdx++) // alle Tasks anschauen
	{ 
		if(TaskPtr[TaskIdx].Interval== 0)
			{
				(*TaskPtr[TaskIdx].Func)();   //  Idle-Task ausf�hren
			}
		else if((tick-TaskPtr[TaskIdx].LastTick) >= TaskPtr[TaskIdx].Interval) 
			{
				(*TaskPtr[TaskIdx].Func)();       // Periodische Tasks ausf�hren
				TaskPtr[TaskIdx].LastTick= tick; // Letzte Ausf�hrungszeit merken
			}
	}
}   