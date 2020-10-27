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
    Functions aimed to ensure the proper operation of the LED components with respect to the 
    requirements
    Author: Daniela Garofalo
*/

#include <LED_CustomFunctions.h>

void LED_Intensity(int32 photoresistor_threshold)
{
    if (flag_sampling == 1) // The signals have been sampled by the ADC
    {
        if (photoresistor_value > 65535)
        {
            photoresistor_value = 65535;
        } else if (photoresistor_value < 0)
        {
            photoresistor_value = 0;
        }
        /* Controlling the value of photoresistor_value variable in order to cope with some 
        eventual errors */
        if (photoresistor_value < photoresistor_threshold) /* The value of the photoresistor
        is lower than the threshold set by the programmer, so the LED must switch ON */
        {
            if (potentiometer_value > 65535)
            {
                potentiometer_value = 65535;
            } else if (potentiometer_value < 0)
            {
                potentiometer_value = 0;
            }
            /* Controlling the value of potentiometer_value variable in order to cope with some 
            eventual errors */
            PWM_WriteCompare(potentiometer_value); /* Setting the value of the compare in order
            to regulate the intensity of the LED according to the acquired value */
            PWM_Start(); // Starting the PWM component in order to switch ON the LED
            flag_sending = 1;
            flag_sampling = 0;
        }
    }
}

/* [] END OF FILE */
