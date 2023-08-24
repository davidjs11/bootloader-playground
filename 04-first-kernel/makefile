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
	@gcc -ffreestanding -c kernel.c -o kernel.o
	@ld -o kernel.bin -Ttext 0x1000 kernel.o --oformat binary 

join:\
	boot_sector.bin\
	kernel.bin
	@echo "[+] joining both boot sector and kernel..."
	@cat boot_sector.bin kernel.bin > os_image

run:\
	join
	@qemu-system-x86_64 os_image 

clean:
	@echo "[+] cleaning..."
	@rm *.o *.bin
