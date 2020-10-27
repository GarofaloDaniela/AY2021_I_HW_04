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

// Definitions related to the transmitted packet
#define SENDING_BYTES 4 // Information dimension: 2 bytes for each signal
#define PACKET_SIZE 1 + SENDING_BYTES + 1 // Overall packet dimension

#define PHOTORESISTOR_THRESHOLD 65535

#define LED_ON 1
#define LED_OFF 0

extern uint8 PacketData[PACKET_SIZE]; 

// Declaration of the external variables used as flags
extern int flag_start;
extern int flag_received;
extern int flag_sampling;
extern int flag_sending;

// Declaration of the variables containing the sampled values
extern int32 potentiometer_value;
extern int32 photoresistor_value;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_ISR_StartEx(custom_UART_ISR);
    ADC_ISR_StartEx(custom_ADC_ISR);
    // Enabling the interrupts
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    SYSTEM_Initialisation();
    
    UART_PutString("Insert 'b' to enable the system, or 's' to disable it\r\n");
    
    for(;;)
    {
        /* Place your application code here. */
        UART_ReceivedData(); /* Function that changes the value of the variable flag_start
        according to the character inserted by the user */
        if (flag_start == 1)
        {
//            LED_Intensity(PHOTORESISTOR_THRESHOLD); /* Function that switches ON the LED
//            according to the value of the potentiometer only if the photoresistor value is 
//            lower than the given threhsold */
            UART_SendingData(); /* Function that sends the information through the serial port
            in order to plot both the analog signal for diagnostic purposes */
//        } else {
//            SYSTEM_Disabling();
        }
    }
}

/* [] END OF FILE */
