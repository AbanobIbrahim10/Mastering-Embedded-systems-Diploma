
void reset_handler ();
extern int main ();
extern unsigned long _Stack_pointer;
void NMI_handler() __attribute__((weak,alias("reset_handler")));

void (* ptr_func[]) (void) __attribute__((section(".vectors")))={


    (void (* ) (void)) &_Stack_pointer,
    &reset_handler,
    &NMI_handler,
    &reset_handler,
    &reset_handler,
    &reset_handler,
    &reset_handler,
    &reset_handler,
    &reset_handler,
    &reset_handler,
    &reset_handler,
    &reset_handler,
    &reset_handler,
    &reset_handler,
    &reset_handler,
    &reset_handler,
    &reset_handler,
    &reset_handler,
    &reset_handler,
    &reset_handler
};


extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;


void reset_handler ()
{

//copy .data section from ROM to SRAM

//size of data section

unsigned int data_size = (unsigned int)((unsigned char*)&_E_data - (unsigned char *)&_S_data);
unsigned int counter=0;
unsigned char * ptr_E_text = (unsigned char*) &_E_text;
unsigned char * ptr_S_data = (unsigned char*) &_S_data;
unsigned char * ptr_E_data = (unsigned char*) &_E_data;
unsigned char * ptr_S_bss  = (unsigned char*) &_S_bss;
unsigned char * ptr_E_bss  = (unsigned char*) &_E_bss;

for(counter=0; counter<data_size ;counter++)
{
    *(ptr_S_data++) = *(ptr_E_text++) ;
}
unsigned char bss_size = (unsigned int)((unsigned char*)&_E_bss - (unsigned char*)&_S_bss);
for(counter=0; counter<bss_size ;counter++)
{
    *(ptr_S_bss++) = 0 ;
}


    main();
}