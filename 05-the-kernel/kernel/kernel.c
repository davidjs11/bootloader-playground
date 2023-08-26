/// kernel.c ////////////////////////////////
#include "ports.h"

// print a string into the vga text buffer
void print_vga(char *buffer, const char *val, const char color)
{
    // print until last character
    while(*val != 0) {
        *buffer = *val;
        buffer++;
        *buffer = color;
        buffer++;
        val++;
    }
}

void main()
{
    // get current VGA cursor position
    int position;
    port_byteOut(0x3D4, 14);        // request cursor high byte
    position = port_byteIn(0x3D5) << 8;

    port_byteOut(0x3D4, 15);        // request cursor low byte
    position |= port_byteIn(0x3D5); 

    position *= 2;                  // offset the value


    // display message into the screen
    char *videoMemory = (char *) 0xB8000;
    print_vga(videoMemory+position, "kernel.c loaded successfully", 0x04);
}
