#include "STD_TYPES.h"
#include "uart.h"



void Uart0_Void_TransmitData( uint_8 * buffer )
{
    uint_32 i=0;
    while (buffer[i] != '\0')
    {
        UART0_UARTDR_UINT32_REG=buffer[i];
        i++;
    }
}