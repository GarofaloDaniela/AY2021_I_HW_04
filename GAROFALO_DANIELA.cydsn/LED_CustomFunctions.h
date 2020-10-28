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
    File LED_CustomFunctions.h
    Function aimed to the inclusion and the definition of of all the libraries and variables 
    necessary for the source code
    Author: Daniela Garofalo
*/
    
#ifndef __LED_CUSTOMFUNCTIONS_H__
    #define __LED_CUSTOMFUNCTIONS_H__
    
    #include <project.h> // Library that contains all the functions related to components in the project
    #include <UART_CustomFunctions.h> /* Library that contains the declaration of all the
    functions related to the UART component */
    
    void LED_Intensity(int32 photoresistor_threshold); /* Declaration of the function that sets the 
    compare value of the PWM component in order to regulate the LED intensity */
    
    int32 photoresistor_value;
    int32 potentiometer_value;
    
#endif

/* [] END OF FILE */
