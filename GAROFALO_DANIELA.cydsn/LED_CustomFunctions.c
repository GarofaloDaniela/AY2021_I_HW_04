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
    // Controlling the consistency of the value acquired from the photoresistor
    if (photoresistor_value > 65535)    photoresistor_value = 65535;
    if (photoresistor_value < 0)        photoresistor_value = 0;
        
    // Controlling the consistency of the value acquired from the potentiometer
    if (potentiometer_value > 65535)    potentiometer_value = 65535;
    if (potentiometer_value < 0)        potentiometer_value = 0;
        
    /* The value of the photoresistor is lower than the threshold set by the programmer, so 
    the LED must switch ON */
    if (photoresistor_value < photoresistor_threshold) 
    {
        PWM_WriteCompare(potentiometer_value); /* Setting the value of the compare in order
        to regulate the intensity of the LED according to the acquired value */
        PWM_Start(); // Starting the PWM component in order to switch ON the LED
    } else {
        PWM_Stop(); // Stopping the PWM component in order to switch OFF the LED
    }
        
    UART_SendingData(); /* Function that sends the information through the serial port in 
    order to plot both the analog signal for diagnostic purposes */
}

/* [] END OF FILE */
