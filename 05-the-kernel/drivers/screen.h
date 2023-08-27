#ifndef SCREEN_H
#define SCREEN_H

#include "util.h"
#include "types.h"

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

void screen_printAt(char *val, u8 row, u8 col, u8 color);
void screen_print(char *val, u8 color);
void screen_moveCursor(u8 row, u8 col);
void screen_clear();
void screen_scroll(u8 rows);


#endif  // SCREEN_H
