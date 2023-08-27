/// isr.c ///////////////////////////////////
#include "isr.h"
#include "screen.h"


void isr_handler(registers_t regs)
{
    char buffer[100];
    screen_print("got a new interrupt! code: ", 0x0A);
    screen_print(itoa(regs.int_no, buffer), 0x0A);
    screen_print("\n", 0x0A);
}
