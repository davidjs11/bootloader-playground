/// kernel.c ////////////////////////////////
#include "ports.h"
#include "screen.h"

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
    // display message into the screen
    char *videoMemory = (char *) 0xB8000;
    print_vga(videoMemory, "kernel.c loaded successfully", 0x04);

    // make the kernel scream
    screen_setCursor(0,0);
    for(int i=0; i<MAX_ROWS*MAX_COLS; i++) {
        print_vga(videoMemory+screen_getCursor(), "A", 0x04);
        screen_setCursorOffset(screen_getCursor()+2);
    }
}
