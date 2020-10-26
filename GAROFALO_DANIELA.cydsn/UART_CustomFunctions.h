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
    Functions aimed to the inclusion and the definition of all the libraries and variables necessary for the source code
    Author: Daniela Garofalo
*/
    
#ifndef __UART_CUSTOMFUNCTIONS_H__
    #define __UART_CUSTOMFUNCTIONS_H__
    
    #include <cytypes.h> // Library that contains the functions CY, included the one necessary to define the prototype of the ISR
    #include <UART.h> // Library that contains all the functions associated to the UART component
    #include <EmbLED_pin.h> // Libraty that contains all the function associated to the LED component
    
#endif

int flag_received; // Flag variable which is set equal to 1 when a data is received through the serial port

CY_ISR_PROTO(custom_UART_ISR); // Declaration of the ISR function
void UART_ReceivedData(); // Declaration of the function that controls the value of the received information

/* [] END OF FILE */
