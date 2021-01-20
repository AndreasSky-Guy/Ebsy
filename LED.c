
 //////////////////////////////
 // SOURCE FILE  LED.c       //
 //////////////////////////////


/**************************************************************************
 *  Eingebettete Betriebssysteme (EBSy)		                                *  
 *                                                                        *
 **************************************************************************
 *  PROJECT       P1                                                      *
 *  MODULE        LED.c                                                   *
 *  REVISION      1.0                                                     *
 *  AUTHOR        Müller Dominik                                          *
 **************************************************************************
 *  PURPOSE:                                                              *
 *  Various functions to cotrol LEDs 																			*
 *   						                                                          *
 *                                                                        *
 *                                                                        *
 **************************************************************************
 *  CHANGE HISTORY:                                                       *
 *   Revision  Date         Author            Description      					  *
 *     1.0    19.10.2020   Müller Dominik     creation                    *
 *     2.0    01.11.2020   Andreas Vieracker  revision                    *
 *     2.1    16.11.2020   Müller Dominik     revision                    *
 *                                                                        *
 *************************************************************************/


/* ---------------- G L O B A L   D E F I N I T I O N S ---------------- */

/*  - I n c l u d e s                                                    */

#include <LPC177x_8x.h>
#include <stdio.h>
#include "LED.h"
#include "ProcessHandler.h"

/* ----------------- G L O B A L    V A R I A B L E S ------------------ */

extern pcb_type processTable[NPROCS]; 
extern uint8_t current_task_id;


/* ------------  F U N C T I O N   D E F I N I T I O N ----------------- */


/*  FUNCTION <LED_init>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    Initialization of GPIOs                															    *
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *    none                                                                    *
 *                                                                            *
 ******************************************************************************
 *  RETURN VALUE                                                              *
 *      none                                                                  *
 *                                                                            *
 ******************************************************************************
 *  CHANGE HISTORY:                                                           *
 *   Revision   Date          Author      			Description                   *
 *      0        19.10.2020    Müller Dominik     creation                    *
 *                                                                            *
 ******************************************************************************/
 
void LED_init(void)
{
	LED_setOutput(LED0);
	LED_setOutput(LED1);
	LED_setOutput(LED2);
	LED_setOutput(LED3);
	LED_setOutput(LED4);
	LED_setOutput(LED5);
	LED_setOutput(LED6);
	LED_setOutput(LED7);
	LED_off(LED0);
	LED_off(LED1);
	LED_off(LED2);
	LED_off(LED3);
	LED_off(LED4);
	LED_off(LED5);
	LED_off(LED6);
	LED_off(LED7);
}

/*  FUNCTION <LED_setInput>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    Set Pin as Input                      															    *
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *   LED PIN                                                                  *
 *                                                                            *
 ******************************************************************************
 *  RETURN VALUE                                                              *
 *      none                                                                  *
 *                                                                            *
 ******************************************************************************
 *  CHANGE HISTORY:                                                           *
 *   Revision   Date          Author      			Description                   *
 *      0        19.10.2020    Müller Dominik     creation                    *
 *                                                                            *
 ******************************************************************************/
void LED_setInput(uint8_t LED)
{
	LPC_GPIO0->DIR &=~(1<<LED);
}

/*  FUNCTION <LED_setOutput>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    Set Pin as Output                      															    *
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *   LED PIN                                                                  *
 *                                                                            *
 ******************************************************************************
 *  RETURN VALUE                                                              *
 *      none                                                                  *
 *                                                                            *
 ******************************************************************************
 *  CHANGE HISTORY:                                                           *
 *   Revision   Date          Author      			Description                   *
 *      0        19.10.2020    Müller Dominik     creation                    *
 *                                                                            *
 ******************************************************************************/
void LED_setOutput(uint8_t LED)
{
	LPC_GPIO0->DIR |=(1<<LED);
}

/*  FUNCTION <LED_on>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    Set Pin in GPIO for LED                															    *
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *   LED PIN                                                                  *
 *                                                                            *
 ******************************************************************************
 *  RETURN VALUE                                                              *
 *      none                                                                  *
 *                                                                            *
 ******************************************************************************
 *  CHANGE HISTORY:                                                           *
 *   Revision   Date          Author      			Description                   *
 *      0        19.10.2020    Müller Dominik     creation                    *
 *                                                                            *
 ******************************************************************************/
void LED_on(uint8_t LED)
{
	LPC_GPIO0->SET |=(1<<LED);
}

/*  FUNCTION <LED_off>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    Clear Pin in GPIO for LED                															  *
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *   LED PIN                                                                  *
 *                                                                            *
 ******************************************************************************
 *  RETURN VALUE                                                              *
 *      none                                                                  *
 *                                                                            *
 ******************************************************************************
 *  CHANGE HISTORY:                                                           *
 *   Revision   Date          Author      			Description                   *
 *      0        19.10.2020    Müller Dominik     creation                    *
 *                                                                            *
 ******************************************************************************/
void LED_off(uint8_t LED)
{
	LPC_GPIO0->CLR |=(1<<LED);
}


/*  FUNCTION <LED_run1>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    running LED 0 to 3 in a while loop executes yield on end of loop		  	* 
 *    																																				*
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *   frequency			                                                          *
 *                                                                            *
 ******************************************************************************
 *  RETURN VALUE                                                              *
 *      none                                                                  *
 *                                                                            *
 ******************************************************************************
 *  CHANGE HISTORY:                                                           *
 *   Revision   Date          Author      			Description                   *
 *      0       01.11.2020    Andreas Vieracker creation                      *
 *      1       16.11.2020    Dominik Müller    revision                      *
 *                                                                            *
 ******************************************************************************/
void LED_run1(void)
{
 while(1)
 {
		for (int i = 0; i<4; i++)
			{
				if (i != 0)
				{
					LED_off(LED0+i-1);
					LED_on(LED0+i);
				}
				else
				{
					LED_on(LED0);
					LED_off(LED3);
				}
			}
		}
}
/*  FUNCTION <LED_run2>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    running LED 4 to 7 in a while loop executes yield on end of loop		  	* 
 *    																																				*
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *   frequency			                                                          *
 *                                                                            *
 ******************************************************************************
 *  RETURN VALUE                                                              *
 *      none                                                                  *
 *                                                                            *
 ******************************************************************************
 *  CHANGE HISTORY:                                                           *
 *   Revision   Date          Author      			Description                   *
 *      0       01.11.2020    Andreas Vieracker creation                      *
 *      1       16.11.2020    Dominik Müller    revision                      *
 *                                                                            *
 ******************************************************************************/
void LED_run2(void)
{
	while(1)
	{
		for (int i = 0; i<4; i++)
			{
				if (i != 0)
				{
					LED_off(LED4+i-1);
					LED_on(LED4+i);
					
				}
				else
				{
					LED_on(LED4);
					LED_off(LED7);
				}
			}
		}
}

/*  FUNCTION <LED_wait>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    wait until timmer hits expected time																  	* 
 *    																																				*
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *   frequency			                                                          *
 *                                                                            *
 ******************************************************************************
 *  RETURN VALUE                                                              *
 *      none                                                                  *
 *                                                                            *
 ******************************************************************************
 *  CHANGE HISTORY:                                                           *
 *   Revision   Date          Author      			Description                   *
 *      0       01.11.2020    Andreas Vieracker creation                      *
 *      1       16.11.2020    Dominik Müller    revision                      *
 *                                                                            *
 ******************************************************************************/

void LED_wait(void)
{
	while(1)
	{
		LPC_TIM1->TC = 0;
		while (LPC_TIM1->TC < 500)
		{
		}
		yield();
	}
	
	
}



