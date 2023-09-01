/// isr.c ///////////////////////////////////

#include "isr.h"
#include "mem.h"
#include "string.h"
#include "ports.h"
#include "screen.h"

// array of function pointers for each interrupt
isr_t interrupt_handlers[256];

// handle interrupt service routines
void isr_handler(registers_t regs)
{
    char buffer[16];
    screen_print("new CPU interrupt! code: ", 0x0A);
    screen_print(itoa(regs.int_no, buffer), 0x0A);
    screen_print("\n", 0x0A);
}

// handle interrupt requests 
void irq_handler(registers_t regs)
{
    char buffer[16];

    // set end of interrupt signal to PIC
    if (regs.int_no >= 40)
        port_byteOut(0xA0, 0x20);
    port_byteOut(0x20, 0x20);

    // call custom function for each IRQ
    if (interrupt_handlers[regs.int_no]) {
        isr_t handler = interrupt_handlers[regs.int_no];
        handler(regs);
    }
}

// register the handler into the handlers array
void register_interrupt_handler(u8 n, isr_t handler)
{
    interrupt_handlers[n] = handler;
}
