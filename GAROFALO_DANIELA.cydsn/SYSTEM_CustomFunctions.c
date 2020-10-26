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
    File SYSTEM_CustomFunctions.c
    Functions aimed to ensure the proper operation of the overll system components with respect 
    to the requirements
    Author: Daniela Garofalo
*/

#include <SYSTEM_CustomFunctions.h>

void SYSTEM_Initialisation()
{
    ADC_DelSig_Start();
    PWM_Init();
    Timer_ADC_Init();
    UART_Start();
    // Initialisation of all the components 
    flag_start = 0;
    flag_received = 0;
    flag_sampling = 0;
    flag_packet = 0;
    potentiometer_value = 0;
    photoresistor_value = 65535; /* Initialisation of the value associated to the photoresistor
    at the maximum number possible in order to avoid the switchin ON of the LED because it is
    surely grater or at least equal to the threhsold set by the programmer */
}

void SYSTEM_Disabling()
{
    ADC_DelSig_StopConvert();
    Timer_ADC_Stop();
    PWM_Stop();
    ExtLED_pin_Write(LED_OFF); // Switching OFF the LED when the system is disabled
}

/* [] END OF FILE */
