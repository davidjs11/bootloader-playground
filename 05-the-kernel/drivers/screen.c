#include "screen.h"
#include "ports.h"

// private function declaration
word screen_getOffset(byte row, byte col);
byte screen_getOffsetRow(word offset);
byte screen_getOffsetCol(word offset);
word screen_getCursorOffset();
void screen_setCursorOffset(word offset);


/// public functions //////////////////////////////////

// print at a given position
void screen_printAt(char *val, byte row, byte col, byte color)
{
    char *videoMemory = (char *) VIDEO_ADDRESS;

    // set the cursor at given offset
    word offset = row*MAX_COLS + col;
    offset *= 2;

    // print the string
    while (*val) {
        // print new line
        if (*val == '\n') {
            offset = screen_getOffset(
                screen_getOffsetRow(offset)+1, 0);
            val++;
        }
        else {
            videoMemory[offset++] = *(val++);
            videoMemory[offset++] = color;
        }
    }
}

// print at the current cursor
void screen_print(char *val, byte color)
{
    char *videoMemory = (char *) VIDEO_ADDRESS;

    // get the current cursor offset
    word offset = screen_getCursorOffset();

    // print the string
    while (*val) {
        // print new line
        if (*val == '\n') {
            offset = screen_getOffset(
                screen_getOffsetRow(offset)+1, 0);
            val++;
        }
        else {
            videoMemory[offset++] = *(val++);
            videoMemory[offset++] = color;
        }
    }

    // set the current cursor offset
    screen_setCursorOffset(offset);
}

// move the cursor to a given position
void screen_moveCursor(byte row, byte col)
{
    screen_setCursorOffset(screen_getOffset(row, col));
}

// clear the screen
void screen_clear()
{
    char *videoMemory = (char *) 0xB8000;

    // clear the screen
    for (int i=0; i<MAX_COLS*MAX_ROWS; i++) {
        videoMemory[i*2] = ' ';
        videoMemory[i*2+1] = WHITE_ON_BLACK;
    }

    // return to first position
    screen_setCursorOffset(0);
}

void screen_scroll(byte rows)
{
    char *videoMemory = (char *) 0xB8000;
    // to-do
}


/// private functions ///////////////////////

// get the offset of a given position
word screen_getOffset(byte row, byte col)
{
    return (row * MAX_COLS + col) * 2;
}

byte screen_getOffsetRow(word offset)
{
    return offset/(2*MAX_COLS);
}

byte screen_getOffsetCol(word offset)
{
    return (offset-(screen_getOffsetRow(offset)*2*MAX_COLS))/2;
}

// get the cursor offset
word screen_getCursorOffset()
{
    word offset;

    // cursor high byte
    port_byteOut(VGA_REG_INDEX, 0x0E);
    offset = port_byteIn(VGA_REG_DATA) << 8;

    // cursor low byte
    port_byteOut(VGA_REG_INDEX, 0x0F);
    offset |= port_byteIn(VGA_REG_DATA);

    return offset * 2;
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
