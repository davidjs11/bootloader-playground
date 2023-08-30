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
    char buffer[256];
    char string1[] = "cadenaA ";
    char string2[] = ".cadenaB";


    // init interrupt stuff
    idt_init();

    // kernel loaded
    screen_clear();
    screen_print("\nkernel loaded succesfully!\n", 0x0A);
    screen_print(str_append(string1, string2), 0x0A);

    // timer and keyboard test
    //timer_init(50);
    keyboard_init();
}

void user_input(char *input)
{
    screen_print(input,  0x0A);
    screen_print("\n> ", 0x00);
}
