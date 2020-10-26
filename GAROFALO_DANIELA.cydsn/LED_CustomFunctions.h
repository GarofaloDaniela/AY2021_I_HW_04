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
    
    #define LED_ON 1
    #define LED_OFF 0
    #define LED_DELAY 200
    #define LED_NUMBER_BLINKING 3
    
    #include <CyLib.h> // Library that contains the function CyDelay used for the LED blinking
    #include <PWM.h> // Library that contains all the functions related to the PWM
    #include <EmbLED_pin.h> /* Library that contains all the functions associated to the
    LED embedded in the PSoC kit */
    
    void LED_Blinking(); /* Declaration of the unction that makes the embedded LED blink at the 
    receiving of a data through the serial port */
    void LED_Intensity(int photoresistor_threshold); /* Declaration of the function that sets the 
    compare value of the PWM component in order to regulate the LED intensity */
    
    int i; // Definition of the index variable that is used only in the LED_Blinking() function
    
    int flag_sampling;
    int flag_received;
    
    int32 photoresistor_value;
    int32 potentiometer_value;
    
#endif

/* [] END OF FILE */
