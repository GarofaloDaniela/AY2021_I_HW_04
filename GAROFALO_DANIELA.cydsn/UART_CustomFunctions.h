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
    File UART_CustomFunctions.h
    Functions aimed to the inclusion and the definition of all the libraries and variables 
    necessary for the source code
    Author: Daniela Garofalo
*/
    
#ifndef __UART_CUSTOMFUNCTIONS_H__
    #define __UART_CUSTOMFUNCTIONS_H__
    
    #define LED_ON 1
    #define LED_OFF 0
    
    #define SENDING_BYTES 4 // Information dimension: 2 bytes for each signal
    #define PACKET_SIZE 1 + SENDING_BYTES + 1 // Overall packet dimension
    
    #include <cytypes.h> /* Library that contains the functions CY, included the one necessary to 
    define the prototype of the ISR */
    #include <project.h> // Library that contains all the functions associated to the components of the project
    
    CY_ISR_PROTO(custom_UART_ISR); // Declaration of the ISR function
    void UART_ReceivedData(); /* Declaration of the function that controls the value of the 
    received information */
    void UART_SendingData(); /* Declaration of the function that sends the sampled values
    through the serial port implementing the UART protocol */
    
    volatile int flag_received;
    volatile int flag_start;
    
    char received_data;
    
    uint8 PacketData[PACKET_SIZE];
    
    int32 potentiometer_value;
    int32 photoresistor_value;

#endif

/* [] END OF FILE */
