/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/*
    File LED_CustomFunctions.c
    Functions aimed to ensure the proper operation of the LED components with respect to the requirements
    Author: Daniela Garofalo
*/

#include <LED_CustomFunctions.h>

#define LED_DELAY 500 

static int i; // Definition of the index variable that is used only in the LED_Blinking() function

void Led_Blinking() // Function that reports that the communication is happening
{
    for(i = 0; i < 3; i++) // Repetition of the blink for three times
    {
        EmbLED_pin_Write(LED_ON);
        CyDelay(LED_DELAY);
        EmbLED_pin_Write(LED_OFF);
        CyDelay(LED_DELAY);
    }
}

void Led_Intensity(int potentiometer_value)
{
    if (potentiometer_value > 255)
    {
        potentiometer_value = 255;
    }
    if (potentiometer_value < 0)
    {
        potentiometer_value = 0;
    }
    // Controlling the value of potentiometer_value variable in order to cope with some eventual errors
    PWM_WriteCompare(potentiometer_value);
}

/* [] END OF FILE */
