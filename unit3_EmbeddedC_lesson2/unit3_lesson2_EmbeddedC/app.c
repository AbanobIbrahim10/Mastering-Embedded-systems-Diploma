#include "STD_TYPES.h"
#include "uart.h"

uint_8 buffer[100]="Hello it is the first lab ";

void main()
{
    extern uint_8 X_arry[20];

    Uart0_Void_TransmitData(buffer);
    Uart0_Void_TransmitData(X_arry);
    while (1)
    {

    }
}