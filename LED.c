
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

/*  FUNCTION <LED_PWM>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    Activating LEDs with an Dudyclycle given by parameters								  *
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *   LED, dutyclycle                                                          *
 *                                                                            *
 ******************************************************************************
 *  RETURN VALUE                                                              *
 *      none                                                                  *
 *                                                                            *
 ******************************************************************************
 *  CHANGE HISTORY:                                                           *
 *   Revision   Date          Author      			Description                   *
 *      0        26.10.2020    Müller Dominik     creation                    *
 *                                                                            *
 ******************************************************************************/
void LED_PWM(uint32_t led, uint32_t dutycycle)
{
	if (LPC_TIM0->TC < dutycycle)
	{	
		LED_on(led);
	}
	else if (LPC_TIM0->TC > dutycycle)
	{
		LED_off(led);
	}
}

/*  FUNCTION <LED_run_smooth>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    creates processes for all LEDs and controlls the dutyclycle for each 		*
 *   one to create a smooth running light																			* 
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
 *      1       09.11.2020    Andreas Vieracker revision                      *
 *      2       16.11.2020    Dominik Müller    revision                      *
 *                                                                            *
 ******************************************************************************/

void LED_run_smooth (uint32_t frequency, uint32_t unused)
	
{
	frequency /=2;
	static uint8_t init = 0;
	static uint8_t LED_ID0 = 0;
	static uint8_t LED_ID1 = 0;
	static uint8_t LED_ID2 = 0;
	static uint8_t LED_ID3 = 0;
	static uint8_t LED_ID4 = 0;
	static uint8_t LED_ID5 = 0;
	static uint8_t LED_ID6 = 0;
	static uint8_t LED_ID7 = 0;
	
	static uint8_t LEDcounter = LED0;
	static uint8_t timing_switch = 0;	
	
	if (init ==0)	//for initial start to create processes, changed in next version
	{
		LED_ID0 = createProcess(&LED_PWM, ready);
		LED_ID1 = createProcess(&LED_PWM, ready);
		LED_ID2 = createProcess(&LED_PWM, ready);
		LED_ID3 = createProcess(&LED_PWM, ready);
		LED_ID4 = createProcess(&LED_PWM, ready);
		LED_ID5 = createProcess(&LED_PWM, ready);
		LED_ID6 = createProcess(&LED_PWM, ready);
		LED_ID7 = createProcess(&LED_PWM, ready);
		
		processTable[LED_ID0].parameter1=LED0;
		processTable[LED_ID1].parameter1=LED1;
		processTable[LED_ID2].parameter1=LED2;
		processTable[LED_ID3].parameter1=LED3;
		processTable[LED_ID4].parameter1=LED4;
		processTable[LED_ID5].parameter1=LED5;
		processTable[LED_ID6].parameter1=LED6;
		processTable[LED_ID7].parameter1=LED7;
		
		processTable[LED_ID0].parameter2=0;	
		processTable[LED_ID1].parameter2=0;
		processTable[LED_ID2].parameter2=0;
		processTable[LED_ID3].parameter2=0;
		processTable[LED_ID4].parameter2=0;
		processTable[LED_ID5].parameter2=0;
		processTable[LED_ID6].parameter2=0;
		processTable[LED_ID7].parameter2=0;
				
		init = 1;
	}
		
	uint8_t dif=LED0-LED_ID0;
	
		if(LPC_TIM1->TC > frequency && timing_switch ==0)
		{
			timing_switch =1;
			if (LEDcounter==LED0)			//switching between diffrent cases of activ LEDs
			{
				processTable[LED_ID0].parameter2=100;
				processTable[LED_ID7].parameter2=50;
				processTable[LED_ID6].parameter2=10;
				processTable[LED_ID5].parameter2=0;
			}
			else if (LEDcounter==LED1)
			{
				processTable[LED_ID1].parameter2=100;
				processTable[LED_ID0].parameter2=50;
				processTable[LED_ID7].parameter2=10;
				processTable[LED_ID6].parameter2=0;
			}
			else if (LEDcounter==LED2)
			{
				processTable[LED_ID2].parameter2=100;
				processTable[LED_ID1].parameter2=50;
				processTable[LED_ID0].parameter2=10;
				processTable[LED_ID7].parameter2=0;
			}
			else
			{
				processTable[LEDcounter-dif].parameter2=100;
				processTable[LEDcounter-dif-1].parameter2=50;
				processTable[LEDcounter-dif-2].parameter2=10;
				processTable[LEDcounter-dif-3].parameter2=0;
			}
		}
		else if (LPC_TIM1->TC > frequency && timing_switch ==1)
		{
			timing_switch = 0;
			LEDcounter++;
			LPC_TIM1->TC = 0;
			
			if(LEDcounter == LED7+1)
			{
				LEDcounter=LED0;						
			}
		}
}

/*  FUNCTION <LED_process_init>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    creates the initial processes of the LED function and destroys the own 	* 
 *    process																																	*
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

void LED_process_init(uint32_t unused1, uint32_t unused2)
{
	destroyProcess(current_task_id);
	uint8_t run_id = createProcess(&LED_run_smooth,ready);
	processTable[run_id].parameter1 = 500;
}

