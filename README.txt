========== bootloader-playground ==========

just tests i made last summer for learning
how are bootloaders developed, how to go
from assembly running on bare-metal to
a high-level language.

environment
    languages: assembly and C
    assembler: nasm
    compiler/linker: gcc/ld for i386
    v.machine: qemu


================= stages ==================

at the moment, there are available five 
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

- 05-the-kernel
    the """kernel""". now with interrupt
    handling! and now it looks a bit like
    a terminal.

i decided to separate them in order to show
the different stages the project has gone
through.


============= current status ==============

the ""kernel"" program is in a primitive state.
it doesn't do barely anything relevant.

drivers:
    - ports.c: basic I/O operations with ports.
    - screen.c: VGA text mode functions.
    - keyboard.c: keyboard interrupt handling.
    - timer.c: timer for programming ticks.

commands:
    - HALT: shuts down CPU.


=============== resources =================

Writing an OS from scratch
https://www.cs.bham.ac.uk//~exr/lectures/opsys/10_11/lectures/os-dev.pdf

OSDev Wiki
https://wiki.osdev.org/

Roll your own toy UNIX-clone OS (James Molloy)
http://www.jamesmolloy.co.uk/tutorial_html/

funny video
https://www.youtube.com/watch?v=2Ufge60nqoc
