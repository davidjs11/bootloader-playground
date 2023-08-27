/// kernel.c ////////////////////////////////
#include "util.h"
#include "ports.h"
#include "screen.h"

void main()
{
    screen_clear();
    screen_print("kernel loaded succesfully!\n", 0x0F);
}
