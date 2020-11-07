 //////////////////////////////
 // HEADER FILE  LED.h       //
 //////////////////////////////


/**************************************************************************
 *  Eingebettete Betriebssysteme (EBSy)                                   *                                                                                                  *
 **************************************************************************
 *  PROJECT       P1                                                      *
 *  MODULE        LED.c                                                   *
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


#ifndef _LED_H
   #define _LED_H

// global type definitions
   #include <stdint.h>




/*************************************************************************/
/* -------------- E X P O R T E D   D E F I N I T I O N S -------------- */
/*************************************************************************/


/*  - T y p e s                                                          */



/*  - C o n s t a n t s                                                  */

#define LED0 8
#define LED1 9
#define LED2 10
#define LED3 11
#define LED4 12
#define LED5 13
#define LED6 14
#define LED7 15

/*  - M a c r o s                                                        */



/*  - P u p b l i c   V a r i a b l e s                                  */



/*  - P u b l i c  F u n c t i o n  P r o t o t y p e s                 */
void LED_setInput(uint8_t LED);
void LED_setOutput(uint8_t LED);
void LED_on(uint8_t LED);
void LED_off(uint8_t LED);
void LED_init(void);
void LED_run1(int frequency);
void LED_run2(int frequency);
void LED_clear1(void);
void LED_clear2(void);
void LED_PWM(int led, int dutycycle);
void LED_run_schmodderd (int frequency);
void LED_clear_all(void);
uint32_t LED_on1(void);

#endif  // _LED_



