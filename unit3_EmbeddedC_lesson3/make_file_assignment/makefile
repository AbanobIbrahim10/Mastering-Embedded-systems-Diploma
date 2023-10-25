CC=arm-none-eabi-
CFLAGS= -g -mcpu=arm926ej-s
INCS= -I .
LIBS=libmylib.a lib.a
LIBSOBJ=$(LIBS:.a=.o)
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
STARTUP= startup.s
STARTUPOBJ=$(STARTUP:.s=.o)

PROJNAME= Uart_project



$(PROJNAME).bin: $(PROJNAME).elf
	$(CC)objcopy.exe -O binary $< $@
	@echo ---------build is done successfully---------

$(PROJNAME).elf: $(OBJ) $(STARTUPOBJ) $(LIBS)
	$(CC)ld.exe -T linkerscript.ld App.o Uart.o Startup.o -l:$(LIBS) -o $@ -Map=mapFile.map

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@


$(STARTUPOBJ): $(STARTUP)
	$(CC)as.exe $(CFLAGS) $< -o $@




%.a: %.o
	$(CC)ar.exe rcs $@ $<

qemu:$(PROJNAME).bin
	qemu-system-arm.exe -M versatilepb -m 128M -nographic -kernel $(PROJNAME).bin


clear:
	rm *.o *.bin *.elf *.map *.a