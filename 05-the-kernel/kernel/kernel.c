/// kernel.c ////////////////////////////////
#include "util.h"
#include "types.h"
#include "ports.h"
#include "screen.h"
#include "idt.h"
#include "isr.h"

void main()
{
    idt_init();
    screen_clear();
    screen_print("kernel loaded succesfully!\n", 0x0F);
    __asm__ __volatile__("int $0x04");
}
