
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

/* ----------------- G L O B A L    V A R I A B L E S ------------------ */



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

void LED_PWM(int led, int dutycycle)
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
void LED_run_schmodderd (int frequency)
	
{
	static uint8_t LEDcounter = LED0;
	static uint8_t direction;
	
	if(direction == 0)
	{
		if(LPC_TIM1->TC < frequency)
		{
			
			LED_PWM(LEDcounter,100);
			LED_PWM(LEDcounter-1,50);
			LED_PWM(LEDcounter-2,10);
								//increment LED
		}
		else
		{
		LED_clear_all();
		LEDcounter++;	
		LPC_TIM1->TC = 0;					//reset Timer
		}
		
		if(LEDcounter == LED7)
			direction = 1;						//change direction
	}
	else
	{
		if(LPC_TIM1->TC < frequency)
		{
			
			LED_PWM(LEDcounter,100);
			LED_PWM(LEDcounter+1,50);
			LED_PWM(LEDcounter+2,10);
								//decrement LED
		}
		else
		{
			LED_clear_all();
			LEDcounter--;	
			LPC_TIM1->TC = 0;					//reset Timer
		}
		
		if(LEDcounter == LED0)
			direction = 0;						//change direction
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
