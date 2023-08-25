HOME 		= .
ROUTINES 	= $(HOME)/routines

all:\
	boot_sector\
	kernel\
	join\
	run

boot_sector:\
	boot_sector.asm\
	$(ROUTINES)/print.asm\
	$(ROUTINES)/print_vga.asm\
	$(ROUTINES)/read_disk.asm\
	$(ROUTINES)/gdt.asm
	@echo "[+] compiling boot sector..."
	@nasm -f bin boot_sector.asm -o boot_sector.bin

kernel:\
	kernel.c
	@echo "[+] compiling kernel..."
	@i386-elf-gcc -ffreestanding -c kernel.c -o kernel.o
	@nasm -f elf kernel_entry.asm -o kernel_entry.o
	@i386-elf-ld -o kernel.bin -Ttext 0x1000 kernel_entry.o kernel.o --oformat binary 

join:\
	boot_sector.bin\
	kernel.bin
	@echo "[+] joining both boot sector and kernel..."
	@cat boot_sector.bin kernel.bin > os_image.bin

run:\
	join
	@qemu-system-i386 -fda os_image.bin

clean:
	@echo "[+] cleaning..."
	@rm *.o *.bin
