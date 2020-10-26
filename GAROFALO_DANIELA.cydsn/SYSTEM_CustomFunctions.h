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
    
    #include <ADC_DelSig.h> /* Libraty that contains all the functions associated to the ADC
    DelSig component */
    #include <Timer_ADC.h> /* Libraty that contains all the functions associated to the timer 
    component */
    #include <PWM.h> /* Libraty that contains all the functions associated to the PWM 
    component */
    #include <ExtLED_pin.h> /* Libraty that contains all the functions associated to the external
    LED component */
    #include <UART.h> /* Libraty that contains all the functions associated to the UART
    component */
    
    void SYSTEM_Initialisation(); /* Declaration of the function that initialises all the 
    components needed by the systems itself to work properly */
    void SYSTEM_Disabling(); /* Declaration of the function that disables all the components
    which are no more needed when the system is waiting for the starting command */
    
    int flag_start;
    int flag_received;
    int flag_sampling;
    int flag_packet;
    
    int32 photoresistor_value;
    int32 potentiometer_value;
    
#endif

/* [] END OF FILE */
