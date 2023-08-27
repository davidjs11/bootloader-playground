/// isr.c ///////////////////////////////////
#include "isr.h"


void isr_handler(registers_t regs)
{
    screen_print("got a new interrupt!\n", 0x0A);
}
