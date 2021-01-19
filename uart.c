//////////////////////////////
 // SOURCE FILE  uart.c       //
 //////////////////////////////


/**************************************************************************
 *  Eingebettete Betriebssysteme (EBSy)		                                *  
 *                                                                        *
 **************************************************************************
 *  PROJECT       P1                                                      *
 *  MODULE        uart                                                   *
 *  REVISION      1.0                                                     *
 *  AUTHOR        Müller Dominik                                          *
 **************************************************************************
 *  PURPOSE:                                                              *
 *  Various functions to control uart																			*
 *   						                                                          *
 *                                                                        *
 *                                                                        *
 **************************************************************************
 *  CHANGE HISTORY:                                                       *
 *   Revision  Date         Author            Description      					  *
 *     1.0    14.12.2020   Müller Dominik     creation                    *
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

void uart_init(uint8_t uart, uint32_t baudrate)
{
}
void uart_open(uint8_t uart)
{
}
void uart_close(uint8_t uart)
{
}
void uart_read(uint8_t uart)
{
}
void uart_write(uint8_t uart, uint32_t data)
{
}
