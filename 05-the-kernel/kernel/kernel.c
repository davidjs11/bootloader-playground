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
    timer_init(1);

    // welcome screen
    screen_clear();
    screen_printAt("WELCOME!", MAX_ROWS/2, MAX_COLS/2-4, 0x0A);
    timer_wait(200);
    screen_clear();

    // init command line
    screen_print("> ", 0x0A);
}
