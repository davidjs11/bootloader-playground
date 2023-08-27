##### directories and files #################
HOME 		= .
BOOT		= $(HOME)/boot
KERNEL		= $(HOME)/kernel
DRIVERS		= $(HOME)/drivers

C_SOURCES	= $(wildcard $(KERNEL)/*.c $(DRIVERS)/*.c)
HEADERS		= $(wildcard kernel/*.h drivers/*.h)
OBJ			= ${C_SOURCES:.c=.o}


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
	@i386-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary 

run: all
	@qemu-system-i386 -fda os_image.bin


##### general rules #########################
%.o: %.c ${HEADERS}
	@echo "[+] compiling $<..."
	@i386-elf-gcc -ffreestanding -c $< -o $@ -I$(DRIVERS) -I$(KERNEL)

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
	@echo "[+] done!"
