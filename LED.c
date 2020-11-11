
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
 *                                                                        *
 *************************************************************************/


/* ---------------- G L O B A L   D E F I N I T I O N S ---------------- */

/*  - I n c l u d e s                                                    */

#include <LPC177x_8x.h>
#include <stdio.h>
#include "LED.h"
#include "eventHandler.h"

/* ----------------- G L O B A L    V A R I A B L E S ------------------ */

extern pcb_type processTable[NPROCS]; 


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
 *    Clear Pin in GPIO for LED                															    *
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


/*  FUNCTION <LED_clear1>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    Clears LEDs 0-3				                															    *
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *      none                                                                  *
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
void LED_clear1(void)
{
	LED_off(LED0);
	LED_off(LED1);
	LED_off(LED2);
	LED_off(LED3);
}

/*  FUNCTION <LED_clear2>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    Clears LEDs 4-7				                															    *
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *      none                                                                  *
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
void LED_clear2(void)
{
	LED_off(LED4);
	LED_off(LED5);
	LED_off(LED6);
	LED_off(LED7);
}

/*  FUNCTION <LED_run1>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    Creates a running light with LEDs 0-3 with variable frequency   		    *
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *      frequency                                                             *
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
 
void LED_run1(int frequency)
{
	static uint8_t LEDcounter1 = LED0;
	static uint8_t direction1;
	
	if(direction1 == 0)
	{
		if(LPC_TIM0->TC > frequency)
		{
			LED_clear1();
			LED_on(LEDcounter1);
			LEDcounter1++;						//increment LED
			LPC_TIM0->TC = 0;					//reset Timer
		}
		if(LEDcounter1 == LED3)
			direction1 = 1;						//change direction
	}
	else
	{
		if(LPC_TIM0->TC > frequency)
		{
			LED_clear1();
			LED_on(LEDcounter1);
			LEDcounter1--;						//decrement LED
			LPC_TIM0->TC = 0;					//reset Timer

		}
		if(LEDcounter1 == LED0)
			direction1 = 0;						//change direction
	}
}

/*  FUNCTION <LED_run2>

 ******************************************************************************
 *  PURPOSE:                                                                  *
 *    Creates a running light with LEDs 4-7 with variable frequency   		    *
 *                                                                            *
 ******************************************************************************
 *  PARAMETER:                                                                *
 *      frequency                                                             *
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
void LED_run2(int frequency)
{
	static uint8_t LEDcounter2 = LED4;
	static uint8_t direction2;
	
	if(direction2 == 0)
	{
		if(LPC_TIM1->TC > frequency)
		{
			LED_clear2();
			LED_on(LEDcounter2);
			LEDcounter2++;						//increment LED
			LPC_TIM1->TC = 0;					//reset Timer

		}
		if(LEDcounter2 == LED7)
			direction2 = 1;						//change direction
	}
	else
	{
		if(LPC_TIM1->TC > frequency)
		{
			LED_clear2();
			LED_on(LEDcounter2);
			LEDcounter2--;						//decrement LED
			LPC_TIM1->TC = 0;					//reset Timer

		}
		if(LEDcounter2 == LED4)
			direction2 = 0;						//change direction
	}
}

void LED_PWM(uint32_t led, uint32_t dutycycle)
{
	if (LPC_TIM0->TC <= dutycycle)
	{	
		LED_on(led);
	}
	else if (LPC_TIM0->TC >= dutycycle)
	{
		LED_off(led);
	}
}



void LED_run_smooth (uint32_t frequency, uint32_t unused)
	
{
	static uint8_t init = 0;
	
	static uint8_t LED_ID0 = 0;
	static uint8_t LED_ID1 = 0;
	static uint8_t LED_ID2 = 0;
	static uint8_t LED_ID3 = 0;
	static uint8_t LED_ID4 = 0;
	static uint8_t LED_ID5 = 0;
	static uint8_t LED_ID6 = 0;
	static uint8_t LED_ID7 = 0;
		
	if (init ==0)	
	{
		LED_ID0 = createProcess(&LED_PWM, waiting);
		LED_ID1 = createProcess(&LED_PWM, waiting);
		LED_ID2 = createProcess(&LED_PWM, waiting);
		LED_ID3 = createProcess(&LED_PWM, waiting);
		LED_ID4 = createProcess(&LED_PWM, waiting);
		LED_ID5 = createProcess(&LED_PWM, waiting);
		LED_ID6 = createProcess(&LED_PWM, waiting);
		LED_ID7 = createProcess(&LED_PWM, waiting);
		
		processTable[LED_ID0].parameter1=LED0;
		processTable[LED_ID1].parameter1=LED1;
		processTable[LED_ID2].parameter1=LED2;
		processTable[LED_ID3].parameter1=LED3;
		processTable[LED_ID4].parameter1=LED4;
		processTable[LED_ID5].parameter1=LED5;
		processTable[LED_ID6].parameter1=LED6;
		processTable[LED_ID7].parameter1=LED7;
				
		init = 1;
	}
			
	static uint8_t LEDcounter = LED0;
	
	uint8_t dif=LED0-LED_ID0;

		if(LPC_TIM1->TC < frequency)
		{
			if (LEDcounter==0)
			{
				processTable[LED_ID0].parameter2=100;
				processTable[LED_ID0].pstatus=ready;
				processTable[LED_ID7].parameter2=50;
				processTable[LED_ID7].pstatus=ready;
				processTable[LED_ID6].parameter2=10;
				processTable[LED_ID6].pstatus=ready;
				processTable[LED_ID5].pstatus=waiting;
			}
			else if (LEDcounter==1)
			{
				processTable[LED_ID1].parameter2=100;
				processTable[LED_ID1].pstatus=ready;
				processTable[LED_ID0].parameter2=50;
				processTable[LED_ID0].pstatus=ready;
				processTable[LED_ID7].parameter2=10;
				processTable[LED_ID7].pstatus=ready;
				processTable[LED_ID6].pstatus=waiting;
			}
			else if (LEDcounter==2)
			{
				processTable[LED_ID2].parameter2=100;
				processTable[LED_ID2].pstatus=ready;
				processTable[LED_ID1].parameter2=50;
				processTable[LED_ID1].pstatus=ready;
				processTable[LED_ID0].parameter2=10;
				processTable[LED_ID0].pstatus=ready;
				processTable[LED_ID7].pstatus=waiting;
			}
			
			else
			{
				processTable[LEDcounter+dif].parameter2=100;
				processTable[LEDcounter+dif].pstatus=ready;
				processTable[LEDcounter+dif-1].parameter2=50;
				processTable[LEDcounter+dif-1].pstatus=ready;
				processTable[LEDcounter+dif-2].parameter2=10;
				processTable[LEDcounter+dif-2].pstatus=ready;
				processTable[LEDcounter+dif-3].pstatus=waiting;
			}
		}
		else
		{
			
			LEDcounter++;
			LPC_TIM1->TC = 0;
			if(LEDcounter == LED7+1)
			{
				LEDcounter=LED0;						
			}
		}
				
		
	
}
void LED_clear_all(void)
{
	LED_off(LED0);
	LED_off(LED1);
	LED_off(LED2);
	LED_off(LED3);
	LED_off(LED4);
	LED_off(LED5);
	LED_off(LED6);
	LED_off(LED7);
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
uint32_t LED_on1()
{
	LPC_GPIO0->SET |=(1<<LED1);
	return 0;
}

void LED_process_init(uint32_t unused1, uint32_t unused2)
{
	createProcess(&LED_run_smooth,ready);
	

}

