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
    File ADC_CustomFunctions.h
    Function aimed to the inclusion and the definition of of all the libraries and variables necessary for the source code
    Author: Daniela Garofalo
*/

#ifndef __ADC_CUSTOMFUNCTIONS_H__
    #define __ADC_CUSTOMFUNCTIONS_H__
    
    #include <cytypes.h> // Library that contains the CY functions, included the one necessary for the definition of the ISR prototype
    #include <ADC_DelSig.h> // Library that contains all the functions related to the ADC component
    #include <Timer_ADC.h> // Library that contains all the functions related to the timer component
    #include <AMux.h> // Library that contains all the functions related to the AMux component

#endif

CY_ISR_PROTO(custom_ADC_ISR); // Declaration of the ISR function

/* [] END OF FILE */
