/// kernel.c ////////////////////////////////
#include "util.h"
#include "types.h"
#include "ports.h"
#include "screen.h"
#include "idt.h"
#include "isr.h"

void main()
{
    char buffer[100];
    idt_init();

    // kernel loaded
    screen_clear();
    screen_print("kernel loaded succesfully!\n", 0x0A);

    // itoa() test
    screen_print("itoa() test: ", 0x0A);
    screen_print(itoa(-4952, buffer), 0x0A);
    screen_print("\n\ninterruption test:\n", 0x0A);

    // interrupt test
    __asm__ __volatile__("int $0x04");
}
