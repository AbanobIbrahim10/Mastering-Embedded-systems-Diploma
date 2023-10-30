ENTRY(reset)

MEMORY
{
    ROM(rx):ORIGIN = 0x08000000 ,LENGTH = 512M
    SRAM(rwx):ORIGIN = 0x20000000 ,LENGTH = 512M

}

SECTIONS
{

.text :
{
    *(.vectors)
    Startup.o(.text)
    *(.text)

}>ROM
.data :
{
    *(.data)
}>SRAM AT> ROM


}