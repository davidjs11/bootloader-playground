/// kernel.c ////////////////////////////////
#include "ports.h"
#include "screen.h"

void main()
{
    char *videoMemory = (char *) 0xB8000;

    // display 25 lines and scroll 10 times

    screen_clear();

    screen_print("line 1\n", 0x0F);
    screen_print("line 2\n", 0x0F);
    screen_print("line 3\n", 0x0F);
    screen_print("line 4\n", 0x0F);
    screen_print("line 5\n", 0x0F);
    screen_print("line 6\n", 0x0F);
    screen_print("line 7\n", 0x0F);
    screen_print("line 8\n", 0x0F);
    screen_print("line 9\n", 0x0F);
    screen_print("line 10\n", 0x0F);
    screen_print("line 11\n", 0x0F);
    screen_print("line 12\n", 0x0F);
    screen_print("line 13\n", 0x0F);
    screen_print("line 14\n", 0x0F);
    screen_print("line 15\n", 0x0F);
    screen_print("line 16\n", 0x0F);
    screen_print("line 17\n", 0x0F);
    screen_print("line 18\n", 0x0F);
    screen_print("line 19\n", 0x0F);
    screen_print("line 20\n", 0x0F);
    screen_print("line 21\n", 0x0F);
    screen_print("line 22\n", 0x0F);
    screen_print("line 23\n", 0x0F);
    screen_print("line 24\n", 0x0F);
    screen_print("line 25", 0x0F);

    screen_scroll(10);
}
