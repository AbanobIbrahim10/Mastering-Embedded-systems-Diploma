
#ifndef UART_H
#define UART_H

#define UART0_UARTDR_UINT32_REG      *((volatile uint_32 *) 0x101f1000)
void Uart0_Void_TransmitData( uint_8 * buffer );


#endif