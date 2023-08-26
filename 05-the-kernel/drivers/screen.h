#ifndef SCREEN
#define SCREEN

#include "utils.h"

/// constants ///////////////////////////////
#define VIDEO_ADDRESS   0xB8000
#define MAX_ROWS        25
#define MAX_COLS        80
#define WHITE_ON_BLACK  0x0F
#define RED_ON_BLACK    0x04

/// vga regs accessing device ports /////////
#define VGA_REG_INDEX   0x3D4
#define VGA_REG_DATA    0x3D5

/// functions ///////////////////////////////

// get/set the current cursor position
word screen_getCursor();
void screen_setCursor(byte row, byte col);
void screen_setCursorOffset(word offset);


#endif  // SCREEN
