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
    File main.c
    Function that is aimed to the initialisation of the system and the calling of the functions
    with respect to the requests
    Author: Daniela Garofalo
*/

#include "project.h"
#include <UART_CustomFunctions.h>
#include <ADC_CustomFunctions.h>
#include <LED_CustomFunctions.h>
#include <SYSTEM_CustomFunctions.h>

#define PHOTORESISTOR_THRESHOLD 32768

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    // Function that initialises all the variables and the components of the device
    SYSTEM_Initialisation();
    
    // Function that sends to the user an explanatory message 
    UART_PutString("Insert 'b' to enable the system, or 's' to disable it\r\n");
    
    for(;;)
    {
        /* Place your application code here. */
        
        UART_ReceivedData(); /* Function that changes the value of the variable flag_start
        according to the character inserted by the user */
        
        if (flag_start == 1)
        {
            if (flag_sampling == 1)
            {
                flag_sampling = 0; // The sampled data are now processed 
                
                LED_Intensity(PHOTORESISTOR_THRESHOLD); /* Function that switches ON the LED
                according to the value of the potentiometer only if the photoresistor value is 
                lower than the given threhsold */
            }
        } else {
            SYSTEM_Disabling();
        }
    }
}

/* [] END OF FILE */
