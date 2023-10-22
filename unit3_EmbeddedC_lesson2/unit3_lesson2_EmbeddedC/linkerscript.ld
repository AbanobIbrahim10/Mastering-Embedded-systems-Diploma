ENTRY(main)

MEMORY
{
    ROM(rwx):ORIGIN = 0X00000000 ,LENGTH 64M
}
SECTIONS
{
    .=0x00010000;
    .STARTUP .:
    {
        Startup.o(.text)
    }
    .TEXT :
    {
        App.o(.text)
        Uart.o(.text)
    }>ROM
    .DATA :
    {
        *(.data)
        
    }>ROM
    .RODATA :
    {
        *(.rodata)
    }>ROM

    .=.+0x1000;
    stack_pointer=.;
}