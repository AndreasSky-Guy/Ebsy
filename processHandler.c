//////////////////////////////
 // SOURCE FILE  ProcessHandler.c       //
 //////////////////////////////


/**************************************************************************
 *  Eingebettete Betriebssysteme (EBSy)		                                *  
 *                                                                        *
 **************************************************************************
 *  PROJECT       P1                                                      *
 *  MODULE        ProcessHandler.c                                          *
 *  REVISION      1.0                                                     *
 *  AUTHOR        Müller Dominik                                          *
 **************************************************************************
 *  PURPOSE:                                                              *
 *  handles events  								 																			*
 *   						                                                          *
 *                                                                        *
 *                                                                        *
 **************************************************************************
 *  CHANGE HISTORY:                                                       *
 *   Revision  Date         Author            Description      					  *
 *     1.0    02.11.2020   Müller Dominik     creation                    *
 *     1.1    16.11.2020   Müller Dominik     changes     		            *
 *     1.2    17.11.2020   Andreas Vieracker  recomment                   *
 *                                                                        *
 *************************************************************************/


/* ---------------- G L O B A L   D E F I N I T I O N S ---------------- */

/*  - I n c l u d e s                                                    */
#include <stdint.h>
#include <LPC177x_8x.h>
#include "ProcessHandler.h"
#include "LED.h"

/* ----------------- G L O B A L    V A R I A B L E S ------------------ */
pcb_type processTable[NPROCS];
uint8_t current_task_id = 0;
uint32_t stack [NPROCS][32];


/* ------------  F U N C T I O N   D E F I N I T I O N ----------------- */


/*  FUNCTION <Sys_Init>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    Initialization of all inital processes 															    *
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *    none								                                                    *
 *                                                                            *
 ******************************************************************************
 *  RETURN VALUE                                                              *
 *      none                                                                  *
 *                                                                            *
 ******************************************************************************
 *  CHANGE HISTORY:                                                           *
 *   Revision   Date          Author      			Description                   *
 *      0       16.11.2020    Müller Dominik    creation                      *
 *                                                                            *
 ******************************************************************************/
void Sys_Init()
{
	createProcess(&LED_process_init,ready); //hier alle Initialprozesse
}

/*  FUNCTION <Sys_Task_Scheduler>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    Cycles through all tasks							 															    *
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *  	none										                                                    *
 *                                                                            *
 ******************************************************************************
 *  RETURN VALUE                                                              *
 *      none                                                                  *
 *                                                                            *
 ******************************************************************************
 *  CHANGE HISTORY:                                                           *
 *   Revision   Date          Author      			Description                   *
 *      0       16.11.2020    Müller Dominik    creation                      *
 *                                                                            *
 ******************************************************************************/
void Sys_Task_Scheduler(void)
{
	for (current_task_id = 0; current_task_id < NPROCS; current_task_id++)
	{
		if (processTable[current_task_id].pstatus == ready)
		{
			processTable[current_task_id].func();	
		}
	}
}
/*  FUNCTION <create Process>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    creates Processes											 															    *
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *  	functionpointer, Initstatus 										                        *
 *                                                                            *
 ******************************************************************************
 *  RETURN VALUE                                                              *
 *      ProcessID                                                             *
 *                                                                            *
 ******************************************************************************
 *  CHANGE HISTORY:                                                           *
 *   Revision   Date          Author      			Description                   *
 *      0       16.11.2020    Müller Dominik    creation                      *
 *                                                                            *
 ******************************************************************************/

pid_t createProcess(void (*func)(void), uint8_t initstatus)
{
	uint8_t processnumber = 0;
	for (int i = 0; i < NPROCS; i++)
		{
			if (processTable[i].pstatus == unused)
			{
				processnumber=i;
				break;							
			}
		}
	processTable[processnumber].sp = (uintptr_t)&(stack[processnumber][31])-9*4;
	stack[processnumber][31] = (uintptr_t)func;
		
		
	pcb_type process;
	process.id = processnumber;
	process.pstatus = initstatus;
	process.func = func;
	processTable[processnumber] = process;
	return process.id;
}

/*  FUNCTION <destroy Process>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    destroy Processes											 															    *
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *  	ProcessID 																			                        *
 *                                                                            *
 ******************************************************************************
 *  RETURN VALUE                                                              *
 *    result		                                                              *
 *                                                                            *
 ******************************************************************************
 *  CHANGE HISTORY:                                                           *
 *   Revision   Date          Author      			Description                   *
 *      0       16.11.2020    Müller Dominik    creation                      *
 *                                                                            *
 ******************************************************************************/

result_t destroyProcess(pid_t pid)
{
	processTable[pid].pstatus=unused;
	processTable[pid].parameter1=0;
	processTable[pid].parameter2=0;
	processTable[pid].func=0;
	processTable[pid].id=0xff;
	
	
	return 0;
}


void yield (void)
{
// Rücksprungadresse LR sichern
// Kontext von laufendem Prozess sichern
// nächsten Prozess auswählen
// sich dem Kontext vom nächsten Prozess wiederherstellen
// nächsten Prozess fortsetzen

}
void switch_context(void)
{
// Wechseln von context
	
}


