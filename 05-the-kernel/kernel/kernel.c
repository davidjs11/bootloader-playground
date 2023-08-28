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
    char buffer[100];
    idt_init();

    // kernel loaded
    screen_clear();
    screen_print("kernel loaded succesfully!\n", 0x0A);

    // interrupt test
    screen_print("\n\ninterruption test:\n", 0x0A);

    __asm__ __volatile__ ("sti");

    // timer and keyboard test
    timer_init(1);
    keyboard_init();
}
