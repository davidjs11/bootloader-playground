##### makefile ##############################

##### directories and files #################

HOME 		= .
BOOT		= $(HOME)/boot
KERNEL		= $(HOME)/kernel
DRIVERS		= $(HOME)/drivers
CPU			= $(HOME)/cpu

C_SOURCES	= $(wildcard $(KERNEL)/*.c $(DRIVERS)/*.c $(CPU)/*.c)
HEADERS		= $(wildcard $(KERNEL)/*.h $(DRIVERS)/*.h $(CPU)/*.h)
OBJ			= ${C_SOURCES:.c=.o $(CPU)/interrupt.o}

CC			= i386-elf-gcc
LINKER		= i386-elf-ld


##### bootable image ########################

all: os_image.bin

os_image.bin:\
	$(BOOT)/boot_sector.bin\
	$(KERNEL)/kernel.bin
	@echo "[+] creating $@..."
	@cat $^ > $@

$(KERNEL)/kernel.bin:\
	$(KERNEL)/kernel_entry.o\
	${OBJ}
	@echo "[+] linking kernel..."
	@$(LINKER) -o $@ -Ttext 0x1000 $^ --oformat binary 


##### commands ##############################

# compile and run vm
run: all
	@qemu-system-i386 -fda os_image.bin

# compile and delete
test: all clean


##### general rules #########################

%.o: %.c ${HEADERS}
	@echo "[+] compiling $<..."
	@$(CC) -ffreestanding -c $< -o $@ -I$(KERNEL) -I$(DRIVERS) -I$(CPU)

%.o: %.asm
	@echo "[+] assembling $<..."
	@nasm -f elf $< -o $@

%.bin: %.asm
	@echo "[+] creating binary for $<..."
	@nasm -f bin $< -o $@


##### cleaning ##############################
clean:
	@echo "[+] cleaning..."
	@rm -fr *.o *.bin 
	@rm -fr $(KERNEL)/*.o $(KERNEL)/*.bin
	@rm -fr $(DRIVERS)/*.o $(DRIVERS)/*.bin
	@rm -fr $(BOOT)/*.o $(BOOT)/*.bin
	@rm -fr $(CPU)/*.o $(CPU)/*.bin
	@echo "[+] done!"
