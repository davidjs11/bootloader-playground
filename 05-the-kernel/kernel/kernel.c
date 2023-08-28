/// kernel.c ////////////////////////////////
#include "util.h"
#include "types.h"
#include "ports.h"
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "idt.h"
#include "isr.h"

void main()
{
    // init interrupt stuff
    idt_init();
    __asm__ __volatile__ ("sti");

    // kernel loaded
    screen_clear();
    screen_print("\nkernel loaded succesfully!\n", 0x0A);

    // timer and keyboard test
    timer_init(50);
    keyboard_init();
}
