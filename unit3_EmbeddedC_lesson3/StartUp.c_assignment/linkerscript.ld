ENTRY(reset_handler)

MEMORY
{
    ROM(rx):ORIGIN = 0x08000000 ,LENGTH = 512M
    SRAM(rwx):ORIGIN = 0x20000000 ,LENGTH = 512M

}

SECTIONS
{
. = 0x08000000;
.text . :
{
    *(.vectors)
    Startup.o(.text)
    *(.text)
    _E_text = .;

}>ROM
.data :
{
    _S_data = .;
    *(.data)
    _E_data = .;
}>SRAM AT> ROM

.bss :
{
    _S_bss = .;
    *(.bss)
    _E_bss = .;
}>SRAM

. = . +0x1000;
_Stack_pointer = .;

}