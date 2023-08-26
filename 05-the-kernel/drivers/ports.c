#include "ports.h"

/// port input //////////////////////////////
byte port_byteIn(word port)
{
    byte result;

    // save input from port 'edx' into 'eax'
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));

    return result;
}

word port_wordIn(word port)
{
    word result;

    // save input from port 'edx' into 'eax'
    __asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));

    return result;
}

/// port output /////////////////////////////
void port_byteOut(word port, byte value)
{
    // send value of 'eax' to port 'edx'
    __asm__("out %%al, %%dx" : : "a" (value), "d" (port));
}

void port_wordOut(word port, word value)
{
    // send value of 'eax' to port 'edx'
    __asm__("out %%ax, %%dx" : : "a" (value), "d" (port));
}
