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
//    AMux_Select(POTENTIOMETR_CH); // Selection of the channel of the AMux related to the potentiometer 
//    ADC_DelSig_StartConvert(); // Starting the conversion of the first signal
//    potentiometer_value = ADC_DelSig_Read32(); // Sampling the input signal
//    ADC_DelSig_StopConvert(); /* Stopping and restarting the conversion between the acquisition of signals coming from 
//    different sources to avoid the contamination of the sampled values */
    AMux_Select(PHOTORESISTOR_CH); // Selection of the channel of the AMux related to the photoresistor
    ADC_DelSig_StartConvert(); // Starting the conversion of second signal
    photoresistor_value = ADC_DelSig_Read32(); // Sampling the input signal
    ADC_DelSig_StopConvert(); // Stopping the conversion of the second signal
    flag_sampling = 1; // Updating of the flag variable related to the sampling
}

/* [] END OF FILE */
