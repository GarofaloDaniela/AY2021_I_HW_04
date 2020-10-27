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
    File SYSTEM_CustomFunctions.h
    Functions aimed to the inclusion and the definition of all the libraries and variables 
    necessary for the source code
    Author: Daniela Garofalo
*/

#ifndef __SYSTEM_CUSTOMFUNCTIONS_H__
    #define __SYSTEM_CUSTOMFUNCTIONS_H__
    
    #define LED_OFF 0
    
    #define HEADER 0xA0 // Header of the packet send through the serial port
    #define TAIL 0xC0 // Tail of the packet send through the serial port
    #define SENDING_BYTES 4 // Information dimension: 2 bytes for each signal
    #define PACKET_SIZE 1 + SENDING_BYTES + 1 // Overall packet dimension
    
    #include <ADC_DelSig.h> /* Libraty that contains all the functions associated to the ADC
    DelSig component */
    #include <Timer_ADC.h> /* Libraty that contains all the functions associated to the timer 
    component */
    #include <PWM.h> /* Libraty that contains all the functions associated to the PWM 
    component */
    #include <UART.h> /* Libraty that contains all the functions associated to the UART
    component */
    
    void SYSTEM_Initialisation(); /* Declaration of the function that initialises all the 
    components needed by the systems itself to work properly */
    void SYSTEM_Disabling(); /* Declaration of the function that disables all the components
    which are no more needed when the system is waiting for the starting command */
    
    int flag_start;
    int flag_received;
    int flag_sampling;
    int flag_sending;
    
    int32 photoresistor_value;
    int32 potentiometer_value;
    
    uint8 PacketData[PACKET_SIZE];
    
#endif

/* [] END OF FILE */
