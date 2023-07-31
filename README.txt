============== os-playground ==============

just tests for learning how operating
systems are developed, from the bootloader
to a simple kernel program, made for the
x86 processors.

languages: assembly and (soon) C
assembler: nasm
virtual machine: qemu


================= stages ==================

at the moment, there are available three
stages of the project

- bootable-helloworld
    uses BIOS interrupts to print text
    into the screen.

- disk-reading
    BIOS interrupts for reading data
    blocks from the disk.

- protectedmode-testing (current)
    creates the GDT and jumps into 32bit
    protected mode of the x86 processor

i decided to separate them in order to show
the different stages the project has gone
through.


=============== resources =================

Writing an OS from scratch
https://www.cs.bham.ac.uk//~exr/lectures/opsys/10_11/lectures/os-dev.pdf

OSDev Wiki
https://wiki.osdev.org/
