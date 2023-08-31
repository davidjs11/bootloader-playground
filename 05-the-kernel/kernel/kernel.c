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
    // general purpose buffer
    char buffer[256];

    // init stuff
    idt_init();
    keyboard_init();
    screen_clear();

    // init command line
    screen_print("> ", 0x0A);
}

void user_input(char *input)
{
    screen_print(input,  0x0A);
    screen_print("\n> ", 0x00);
}
