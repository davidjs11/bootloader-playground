/// keyboard.c //////////////////////////////
#include "keyboard.h"
#include "idt.h"
#include "isr.h"
#include "screen.h"
#include "ports.h"

/* TO-DO */

void keyboard_callback(registers_t regs)
{
    screen_print("keyboard: ", 0x04);
    u8 scancode = port_byteIn(0x60);
    char sc_ascii[16];

    itoa(scancode, sc_ascii);

    screen_print(sc_ascii, 0x04);
    screen_print("\n", 0x04);
}

void keyboard_init()
{
    register_interrupt_handler(IRQ1, keyboard_callback);
}
