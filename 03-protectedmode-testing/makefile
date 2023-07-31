all:\
	compile\
	run

compile:\
	main.asm\
	print.asm\
	print_hex.asm\
	print_vga.asm\
	read_disk.asm
	nasm -f bin main.asm -o main.bin

run:\
	compile
	qemu-system-x86_64 main.bin
