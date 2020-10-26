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
    Functions aimed to ensure the proper operation of the ADC components with respect to the requirements
    Author: Daniela Garofalo
*/
    
#include <ADC_CustomFunctions.h>

#define PHOTORESISTOR_CH 0
#define POTENTIOMETR_CH 1

uint16 potentiometer_value;
uint16 photoresistor_value;

int flag_potentiometer;
int flag_photoresistor;

CY_ISR_PROTO(custom_ADC_ISR)
{
    if (flag_potentiometer == 0)
    {
        AMux_Select(POTENTIOMETR_CH);
        potentiometer_value = ADC_DelSig_Read32();
        flag_potentiometer = 1;
    }
    if (flag_photoresistor == 0)
    {
        AMux_Select(PHOTORESISTOR_CH);
        photoresistor_value = ADC_DelSig_Read32();
        flag_photoresistor = 1;
    }
}
    

/* [] END OF FILE */
