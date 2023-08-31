/// timer.c /////////////////////////////////

#include "timer.h"
#include "isr.h"
#include "screen.h"
#include "ports.h"

u32 tick = 0;
char buffer[16];

// function called by timer interrupt handler
void timer_callback(registers_t regs)
{
    tick++; // update tick
}

// get the current tick count
u32 timer_getTicks()
{
    return tick;
}

// reset the timer
void timer_reset()
{
    tick = 0;
}

// wait 'n' ticks
void timer_wait(u32 n) {
    // get the current tick counter
    u32 currentTicks = tick;

    // loop until it increases 'n'
    while(tick < currentTicks + n);
}

// initialize the timer
void timer_init(u32 frequency)
{
    screen_print("\ninitializing timer...\n", 0x0A);
    
    // register the timer callback into the handler array
    register_interrupt_handler(IRQ0, &timer_callback);

    u32 divisor = 1193180 / frequency;

    // send the command byte
    port_byteOut(0x43, 0x36);

    // send the frequency divisor
    port_byteOut(0x40, (u8) LOWEST8(divisor));
    port_byteOut(0x40, (u8) HIGHEST8(divisor));
}

