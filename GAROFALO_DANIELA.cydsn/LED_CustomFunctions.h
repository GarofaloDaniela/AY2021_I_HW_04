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
    Function aimed to the inclusion and the definition of of all the libraries and variables necessary for the source code
    Author: Daniela Garofalo
*/
    
#ifndef __LED_CUSTOMFUNCTIONS_H__
    #define __LED_CUSTOMFUNCTIONS_H__
    
    #define LED_ON 1
    #define LED_OFF 0
    
    #include <CyLib.h> // Library that contains the function CyDelay used for the LED blinking
    #include <PWM.h> // Library that contains all the functions related to the PWM
    #include <EmbLED_pin.h> /* Library that contains all the functions associated to the
    LED embedded in the PSoC kit */
    
    void LED_Blinking();
    void LED_Intensity(int potentiometer_value);
#endif

/* [] END OF FILE */
