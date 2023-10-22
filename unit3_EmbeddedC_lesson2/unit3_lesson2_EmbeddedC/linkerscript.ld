ENTRY(reset)

MEMORY
{
    Mem(rwx):ORIGIN = 0X00000000 ,LENGTH =64M
}
SECTIONS
{
    . =0x00010000;
    .STARTUP :
    {
        Startup.o(.text)
    }>Mem
    .TEXT :
    {
        *(.text)
    }>Mem
    .DATA :
    {
        *(.data)
        
    }>Mem
    .RODATA :
    {
        *(.rodata)
    }>Mem

    . =. + 0x1000 ;
    stack_pointer =.;
}