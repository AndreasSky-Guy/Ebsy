 //////////////////////////////
 // HEADER FILE  timer.h       //
 //////////////////////////////


/**************************************************************************
 *  Eingebettete Betriebssysteme (EBSy)                                   *                                                                                                  *
 **************************************************************************
 *  PROJECT       P1                                                      *
 *  MODULE        timer                                                   *
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
 *     1.0    19.10.2020   Müller Dominik 		creation                    *
 *                                                                        *
 *                                                                        *
 *************************************************************************/


#ifndef _TIMER_H
   #define _TIMER_H

// global type definitions
   #include <stdint.h>




/*************************************************************************/
/* -------------- E X P O R T E D   D E F I N I T I O N S -------------- */
/*************************************************************************/


/*  - T y p e s                                                          */



/*  - C o n s t a n t s                                                  */
#define TIMER0 1
#define TIMER1 2
#define TIMER2 22
#define TIMER3 23

/*  - M a c r o s                                                        */



/*  - P u p b l i c   V a r i a b l e s                                  */



/*  - P u b l i c  F u n c t i o n  P r o t o t y p e s                  */

void timer_init(int timer, int prescaleValue);

#endif  // _TIMER_




