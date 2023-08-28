/// isr.c ///////////////////////////////////
#include "isr.h"
#include "ports.h"
#include "screen.h"

isr_t interrupt_handlers[256];

// handle interrupt service routines
void isr_handler(registers_t regs)
{
    char buffer[16];
    screen_print("got a new interrupt! code: ", 0x0A);
    screen_print(itoa(regs.int_no, buffer), 0x0A);
    screen_print("\n", 0x0A);

    // call custom function for each IRS
    if (interrupt_handlers[regs.int_no]) {
        isr_t handler = interrupt_handlers[regs.int_no];
        handler(regs);
    }
}

// handle interrupt requests 
void irq_handler(registers_t regs)
{
    char buffer[16];

    screen_print("got a new interrupt request! code: ", 0x0A);
    screen_print(itoa(regs.int_no, buffer), 0x0A);
    screen_print("\n", 0x0A);

    // set end of interrupt signal to PIC
    if (regs.int_no >= IRQ7)
        port_byteOut(PIC2, 0x20);
    else
        port_byteOut(PIC1, 0x20);


    // call custom function for each IRQ
    if (interrupt_handlers[regs.int_no]) {
        screen_print("found a handler entry!\n", 0x0A);
        isr_t handler = interrupt_handlers[regs.int_no];
        handler(regs);
    }
}

// register the handler into the handlers array
void register_interrupt_handler(u8 n, isr_t handler)
{
    interrupt_handlers[n] = handler;
}
