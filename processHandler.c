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
 *		 2.0		30.11.2020   Andreas Vieracker 	rework											*
 *     2.1    07.12.2020   Andreas Vieracker  revision                    *
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
uint32_t stack [NPROCS][32];
uintptr_t cur;
uintptr_t nxt;


/* ------------  F U N C T I O N   D E F I N I T I O N ----------------- */

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
 *      0       23.11.2020    Andreas Vieracker creation                      *
 *      0       07.12.2020    Andreas Vieracker creation                      *
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
	uintptr_t stackpointer = (uintptr_t)&(stack[processnumber][31])-8*4;
	stack[processnumber][31] = (uintptr_t)func;
			
	pcb_type process;
	process.id = processnumber;
	process.pstatus = initstatus;
	process.sp = stackpointer; 
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
 *      1       16.11.2020    Andreas Vieracker revision                      *
 *                                                                            *
 ******************************************************************************/

result_t destroyProcess(pid_t pid)
{
	processTable[pid].pstatus=unused;
	processTable[pid].func=0;
	processTable[pid].id=0xff;
	processTable[pid].sp=0;
	
	
	return 0;
}


/*  FUNCTION <yield>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *   // Rücksprungadresse LR sichern																					*
 *	 // Kontext von laufendem Prozess sichern																	*
 *	 // nächsten Prozess auswählen																						*
 *   // sich dem Kontext vom nächsten Prozess wiederherstellen								*
 *   // nächsten Prozess fortsetzen									 													*
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
 *      0       23.11.2020    Andreas Vieracker creation                   		*
 *      1       30.11.2020    Müller Dominik    revision                      *
 *      2       07.12.2020    Andreas Vieracker revision                      *
 *                                                                            *
 ******************************************************************************/
void yield (void)
{

	static int processcounter = 0;
	save_context(&processTable[processcounter].sp);

	for (int i = processcounter+1; i <= NPROCS; i++)
		{
			if (i == NPROCS)
			{
					processcounter= 0;
					break;
			}
			
			if (processTable[i].pstatus == ready)
			{
				processcounter=i;
				break;
			}
		}


	load_context(&processTable[processcounter].sp);
		
	//if(processTable[processcounter].pstatus == ready)
	//{
	//	processTable[processcounter].pstatus = running;
	//	first_context(processTable[new_stack].sp);
	//}
	
  //switch_context(&processTable[old_stack].sp, &processTable[new_stack].sp, lrReg);
	
}

/*  FUNCTION <yield>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *   // gets called if a hardfault occurs																			*
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
 *      0       30.11.2020    Müller Dominik    creation                      *
 *                                                                            *
 ******************************************************************************/

void HardFault_Handler(void)
{
	//kaputt
	while(1);
}

//void PendSV_Handler(void)
//{
//	//save min context
//	//set exc_return code in LR
//	//change execution mode?
//	//switch to new stack?
//	//retrieve new pc from vector table
//	
//	
//	SCB->ICSR |= SCB_ICSR_PENDSVCLR_Msk;
//	static int processcounter = 0;
//	

//	for (int i = processcounter+1; i <= NPROCS; i++)
//		{
//			if (i == NPROCS)
//			{
//					processcounter= 0;
//					break;
//			}
//			
//			if (processTable[i].pstatus == ready)
//			{
//				processcounter=i;
//				break;
//			}
//		}
//}

	//save_context(&processTable[processcounter].sp);
	//load_context(&processTable[processcounter].sp);
	
void SysTick_Handler(void)
{
	
	SCB->ICSR |= SCB_ICSR_PENDSTCLR_Msk;
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
	static int processcounter = 0;
	static uint8_t f1context = 1;
	if (f1context==1)
	{
		f1context = 0;
		nxt=(uintptr_t)&processTable[0].sp;
		first_context();
	}
	cur=(uintptr_t)&processTable[processcounter].sp;
	for (int i = processcounter+1; i <= NPROCS; i++)
		{
			if (i == NPROCS)
			{
					processcounter= 0;
					break;
			}
			
			if (processTable[i].pstatus == ready)
			{
				processcounter=i;
				break;
			}
			
		}
	nxt=(uintptr_t)&processTable[processcounter].sp;
}

