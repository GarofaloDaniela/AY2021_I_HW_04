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
    File UART_CustomFunctions.c
    Functions aimed to ensure the proper operation of the UART component with respect to the 
    requirements
    Author: Daniela Garofalo
*/
    
#include <UART_CustomFunctions.h>

CY_ISR_PROTO(custom_UART_ISR)
{
    if (UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY) // Control that a data has been received
    {
        flag_received = 1; /* Change the value of the flag according to the receiving of an 
        information */
    }
}

void UART_ReceivedData()
{
    if (flag_received == 1) // Received data
    {
        received_data = UART_GetByte(); /* Function that gives the byte but also eventual error 
        messages */
        switch (received_data) // Evaluation of the information received from the serial port
        {
            case 'B':
            case 'b':
            {
                flag_start = 1; /* Starting the acquisition of potentiometer and photoresistor 
                values in order to switch ON the LED with the correct light intensity */
                break;
            }
            case 'S':
            case 's':
            {
                flag_start = 0; /* Stopping the acquisition of the potentiometer and photoresistor 
                values and switching OFF the LED independently from its current state */
                break;
            }
            default: // Operations done in all the other cases
            {
                break;
            }
        }
    }
}

void UART_SendingData()
{
    potentiometer_value = ADC_DelSig_CountsTo_mVolts(potentiometer_value);
    photoresistor_value = ADC_DelSig_CountsTo_mVolts(photoresistor_value);
    PacketData[1] = potentiometer_value >> 8; // MORE significant bits
    PacketData[2] = potentiometer_value & 0xFF; // LEAST significant bits
    PacketData[3] = photoresistor_value >> 8; // MORE significant bits
    PacketData[4] = photoresistor_value & 0xFF; // LEAST significant bits
    flag_packet = 1;
    UART_PutArray(PacketData, PACKET_SIZE); /* Transmission of the information related to the
    sampled values of both photoresistor and potentiometer */
}

/* [] END OF FILE */
