#include "screen.h"
#include "ports.h"

// get the cursor offset
word screen_getCursor()
{
    word pos;

    // cursor high byte
    port_byteOut(VGA_REG_INDEX, 0x0E);
    pos = port_byteIn(VGA_REG_DATA) << 8;

    // cursor low byte
    port_byteOut(VGA_REG_INDEX, 0x0F);
    pos |= port_byteIn(VGA_REG_DATA);

    pos *= 2;   // get the real offset
    
    return pos;
}

// set the cursor position
void screen_setCursor(byte row, byte col)
{
    word pos = row*MAX_ROWS + col;

    // cursor high byte
    port_byteOut(VGA_REG_INDEX, 0x0E);
    port_byteOut(VGA_REG_DATA, pos>>8);

    // cursor low byte
    port_byteOut(VGA_REG_INDEX, 0x0F);
    port_byteOut(VGA_REG_DATA, pos);
}

// set the cursor offset
void screen_setCursorOffset(word offset)
{
    offset /= 2;

    // cursor high byte
    port_byteOut(VGA_REG_INDEX, 0x0E);
    port_byteOut(VGA_REG_DATA, offset>>8);

    // cursor low byte
    port_byteOut(VGA_REG_INDEX, 0x0F);
    port_byteOut(VGA_REG_DATA, offset);
}
