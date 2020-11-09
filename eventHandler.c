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
 *                                                                        *
 *************************************************************************/


/* ---------------- G L O B A L   D E F I N I T I O N S ---------------- */

/*  - I n c l u d e s                                                    */
#include <stdint.h>
#include <LPC177x_8x.h>
#include "eventHandler.h"
#include "LED.h"
#include "systemTick.h"


//static TaskType Tasks[] = {
//{ 0,              0, Tsk        },
//{ INTERVAL_10ms,  0, Tsk_10ms   },
//{ INTERVAL_50ms,  0, Tsk_50ms   },
//{ INTERVAL_100ms, 0, Tsk_100ms  },
//};


// static uint32_t tick = 0;          //   System“tick“: aktuelle Zeit
//static TaskType *TaskPtr = Tasks;  // Zeiger auf Prozesstabelle
//static uint8_t  TaskIdx = 0;       // Aktueller Task („Index“)
//const uint8_t  NumTasks = sizeof(Tasks) / sizeof(*Tasks);  // Anzahl Tasks
 pcb_type processTable[NPROCS];



void Sys_Init()
{
	
	//uint32_t (*func)(uint8_t parameter);
	//func = &LED_PWM_0;
	createProcess(&LED_process_init,init);
	

}


void Sys_Task_Scheduler(void)
{
	
	for (int i = 0; i < NPROCS; i++)
		{

			if (processTable[i].pstatus == ready)
			{
							processTable[i].func(processTable[i].parameter1, processTable[i].parameter2);	
					
			}
			else if (processTable[i].pstatus == init)
			{
							processTable[i].func(processTable[i].parameter1, processTable[i].parameter2);	
							destroyProcess(i);
					
			}
		}
}


pid_t createProcess(void (*func)(uint32_t parameter1, uint32_t parameter2), uint8_t initstatus)
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
	pcb_type process;
	process.id = processnumber;
	process.pstatus = initstatus;
	
	process.func = func;
	
	processTable[processnumber] = process;
	
	return process.id;
}

result_t destroyProcess(pid_t pid)
{
	processTable[pid].pstatus=unused;
	return 0;
}



//void handle()
//{
//	tick = Timer_GetSystemTick();    // aktuelle Zeit ermitteln
//	for(TaskIdx= 0; TaskIdx < NumTasks; TaskIdx++) // alle Tasks anschauen
//	{ 
//		if(TaskPtr[TaskIdx].Interval== 0)
//			{
//				(*TaskPtr[TaskIdx].Func)();   //  Idle-Task ausführen
//			}
//		else if((tick-TaskPtr[TaskIdx].LastTick) >= TaskPtr[TaskIdx].Interval) 
//			{
//				(*TaskPtr[TaskIdx].Func)();       // Periodische Tasks ausführen
//				TaskPtr[TaskIdx].LastTick= tick; // Letzte Ausführungszeit merken
//			}
//	}
//}   
