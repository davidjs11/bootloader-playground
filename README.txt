============== os-playground ==============

just tests for learning how operating
systems are developed, from the bootloader
to a simple kernel program, made for the
x86 processors.

environment
    languages: assembly and C
    assembler: nasm
    compiler/linker: custom builds for i386
    machine: qemu


================= stages ==================

at the moment, there are available four 
stages of the project

- 01-bootable-helloworld
    uses BIOS interrupts to print text
    into the screen.

- 02-disk-reading
    BIOS interrupts for reading data
    blocks from the disk.

- 03-protectedmode
    creates the GDT and jumps into 32bit
    protected mode of the x86 processor.

- 04-first-kernel
    first steps into writing the kernel
    program in C, by compiling a simple test
    and linking it with the bootloader.


i decided to separate them in order to show
the different stages the project has gone
through.

- extra: c-test
    just testing how C code, such as variables,
    function calls and pointers are compiled
    into machine code, using objdump and
    ndisasm.


=============== resources =================

Writing an OS from scratch
https://www.cs.bham.ac.uk//~exr/lectures/opsys/10_11/lectures/os-dev.pdf

OSDev Wiki
https://wiki.osdev.org/

funny video
https://www.youtube.com/watch?v=2Ufge60nqoc
