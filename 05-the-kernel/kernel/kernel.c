/// kernel.c ////////////////////////////////
#include "ports.h"
#include "screen.h"

void main()
{
    char *videoMemory = (char *) 0xB8000;

    // display message into the screen
    screen_clear();
    screen_print("\n\n\n\n\nkernel.c loaded successfully!", 0x0F);
    screen_scroll(2);
}
