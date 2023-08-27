#include "ports.h"

/// port input //////////////////////////////
u8 port_byteIn(u16 port)
{
    u8 result;

    // save input from port 'edx' into 'eax'
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));

    return result;
}

u16 port_wordIn(u16 port)
{
    u16 result;

    // save input from port 'edx' into 'eax'
    __asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));

    return result;
}

/// port output /////////////////////////////
void port_byteOut(u16 port, u8 value)
{
    // send value of 'eax' to port 'edx'
    __asm__("out %%al, %%dx" : : "a" (value), "d" (port));
}

void port_wordOut(u16 port, u16 value)
{
    // send value of 'eax' to port 'edx'
    __asm__("out %%ax, %%dx" : : "a" (value), "d" (port));
}
