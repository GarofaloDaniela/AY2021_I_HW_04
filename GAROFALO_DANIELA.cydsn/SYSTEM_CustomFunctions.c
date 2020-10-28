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
    // Initialisation of all the components 
    ADC_DelSig_Init();
    PWM_Init();
    Timer_ADC_Init();
    UART_Start();
    AMux_Start();
    
    // Initialisation of the flag variables
    flag_start = 0;
    flag_received = 0;
    flag_sampling = 0;
    
    // Initialisation of the variables that will contain the sampled values
    potentiometer_value = 0;
    photoresistor_value = 65535; /* Initialisation of the value associated to the photoresistor
    at the maximum number possible in order to avoid the switchin ON of the LED because it is
    surely grater or at least equal to the threhsold set by the programmer */
    
    // Initialisation of the bytes that represent the beginning and the end of each packet
    PacketData[0] = HEADER;
    PacketData[PACKET_SIZE - 1] = TAIL;
    
    // Enabling the local interrupts
    UART_ISR_StartEx(custom_UART_ISR);
    ADC_ISR_StartEx(custom_ADC_ISR);
}

void SYSTEM_Disabling()
{
    ADC_DelSig_Stop();
    Timer_ADC_Stop();
    PWM_Stop();
}

/* [] END OF FILE */
