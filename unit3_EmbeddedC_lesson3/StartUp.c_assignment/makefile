CC=arm-none-eabi-
CFLAGS= -gdwarf-2 -mcpu=cortex-m3
INCS= -I .
LIBS=
LIBSOBJ=$(LIBS:.a=.o)
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
STARTUP= startup.c
STARTUPOBJ=$(STARTUP:.c=.o)

PROJNAME=Stm32_LedBlink



$(PROJNAME).bin: $(PROJNAME).elf
	$(CC)objcopy.exe -O binary $< $@
	cp $(PROJNAME).bin $(PROJNAME).hex
	@echo ---------build is done successfully---------

$(PROJNAME).elf: $(OBJ) $(LIBS)
	$(CC)ld.exe -T linkerscript.ld $(OBJ) $(LIBS) -o $@ -Map=mapFile.map

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@




%.a: %.o
	$(CC)ar.exe rcs $@ $<

qemu:$(PROJNAME).bin
	qemu-system-arm.exe -M versatilepb -m 128M -nographic -kernel $(PROJNAME).bin


clear:
	rm *.o *.bin *.elf *.map *.hex