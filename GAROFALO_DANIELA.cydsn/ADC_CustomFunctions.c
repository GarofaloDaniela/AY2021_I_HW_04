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
    File ADC_CustomFunctions.c
    Functions aimed to ensure the proper operation of the ADC components with respect to the 
    requirements
    Author: Daniela Garofalo
*/
    
#include <ADC_CustomFunctions.h>

CY_ISR(custom_ADC_ISR)
{
    Timer_ADC_ReadStatusRegister(); /* Function that allows to generate again an interrupt when the timer reaches 
    the end of the coutings */
    
    // Sampling of the first analog signal 
    AMux_FastSelect(POTENTIOMETR_CH); // Selection of the channel of the AMux related to the potentiometer 
    potentiometer_value = ADC_DelSig_Read32(); // Sampling the input signal
    
    // Sampling of the second analog signal 
    AMux_FastSelect(PHOTORESISTOR_CH); // Selection of the channel of the AMux related to the photoresistor
    photoresistor_value = ADC_DelSig_Read32(); // Sampling the input signal
    
    flag_sampling = 1; // Updating of the flag variable related to the sampling
}

/* [] END OF FILE */
