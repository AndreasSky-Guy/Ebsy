//////////////////////////////
 // HEADER FILE  LED.h       //
 //////////////////////////////


/**************************************************************************
 *  Eingebettete Betriebssysteme (EBSy)                                   *                                                                                                  *
 **************************************************************************
 *  PROJECT       P1                                                      *
 *  MODULE        ProcessHandler.c                                          *
 *  REVISION      1.0                                                     *
 **************************************************************************
 *  PURPOSE:                                                              *
 *    
 *                                                                        *
 **************************************************************************
 *  REMARKS:                                                              *
 *                                                                        *
 *                                                                        *
 **************************************************************************
 *  CHANGE HISTORY:                                                       *
 *   Revision  Date         Author      			Description                 *
 *     1.0    19.10.2020   M�ller Dominik 		creation                    *
 *                                                                        *
 *                                                                        *
 *************************************************************************/


#ifndef _PROCESSHANDLER_H
   #define _PROCESSHANDLER_H

// global type definitions
   #include <stdint.h>
	 #include <LPC177x_8x.h>




/*************************************************************************/
/* -------------- E X P O R T E D   D E F I N I T I O N S -------------- */
/*************************************************************************/


/*  - T y p e s                                                          */

typedef uint32_t result_t;
typedef uint32_t pid_t;

typedef struct {
	pid_t id;
	uint8_t pstatus;
	void (*func)(void);
	uintptr_t sp;
	} pcb_type;

/*  - C o n s t a n t s  	*/

	#define NPROCS 3

enum processStatus {
	unused,
	running,
	ready,
	waiting
};

/*  - M a c r o s                                                        */



/*  - P u p b l i c   V a r i a b l e s                                  */



/*  - P u b l i c  F u n c t i o n  P r o t o t y p e s                 */

pid_t createProcess(void (*func)(void), uint8_t initstatus);
result_t destroyProcess(pid_t pid);
void yield (void);
extern void save_context(uintptr_t *stack);
extern void load_context(uintptr_t *stack);
extern void first_context(uintptr_t *stack);
void HardFault_Handler(void);


#endif  //_PROCESSHANDLER_H








