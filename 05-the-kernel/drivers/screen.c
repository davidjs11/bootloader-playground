#include "screen.h"
#include "ports.h"

// private function declaration
u16 getOffset(u8 row, u8 col);
u8 getOffsetRow(u16 offset);
u8 getOffsetCol(u16 offset);
u16 getCursorOffset();
void setCursorOffset(u16 offset);


/// public functions //////////////////////////////////

// print at a given position
void screen_printAt(char *val, u8 row, u8 col, u8 color)
{
    char *videoMemory = (char *) VIDEO_ADDRESS;

    // set the cursor at given offset
    u16 offset = row*MAX_COLS + col;
    offset *= 2;

    // print the string
    while (*val) {
        // print new line
        if (*val == '\n') {
            offset = getOffset(
                getOffsetRow(offset)+1, 0);
            val++;

            if (getOffsetRow(offset) == MAX_ROWS) {
                screen_scroll(20);
            }
        }
        else {
            videoMemory[offset++] = *(val++);
            videoMemory[offset++] = color;
        }
    }
}

// print at the current cursor
/*
void screen_print(char *val, u8 color)
{
    char *videoMemory = (char *) VIDEO_ADDRESS;

    // get the current cursor offset
    u16 offset = getCursorOffset();

    // print the string
    while (*val) {
        // print new line
        if (*val == '\n') {
            offset = getOffset(
                getOffsetRow(offset)+1, 0);
            val++;

            if (offset >= MAX_ROWS*MAX_COLS*2) {
                int i;
                for(i=1; i<MAX_ROWS; i++)
                    memcpy(getOffset(0, i) + videoMemory,
                           getOffset(0, i-1) + videoMemory,
                           MAX_COLS * 2);

                char *last_line;
                last_line=getOffset(0, MAX_ROWS-1)+videoMemory;
                for(i=0; i<MAX_COLS*2; i++) last_line[i] = 0;

                offset -= 2*MAX_COLS;
            }
            
        }
        else {
            videoMemory[offset++] = *(val++);
            videoMemory[offset++] = color;
        }
    }

    // set the current cursor offset
    setCursorOffset(offset);
}
*/

void screen_print(char *str, u8 color)
{
    u16 offset = getCursorOffset();

    while(*str) {

        // new line
        if (*str == '\n') {
            offset = getOffset(getOffsetRow(offset)+1, 0);
        }

        // normal line
        else {
            *((char *) VIDEO_ADDRESS + offset++) = *str;
            *((char *) VIDEO_ADDRESS + offset++) = color;
        }

        // scroll when screen is full
        while(offset >= MAX_ROWS*MAX_COLS*2) {
            // put lines back
            memcpy(
                (char *) VIDEO_ADDRESS,
                (char *) VIDEO_ADDRESS+2*MAX_COLS,
                (MAX_ROWS-1)*MAX_COLS*2
            );

            // delete last line
            memset(
                (char *)VIDEO_ADDRESS+2*MAX_COLS*(MAX_ROWS-1),
                0,
                2*MAX_COLS
            );

            // set offset one row back
            offset -= MAX_COLS*2;
        }

        str++;  // increment pointer
    }
    
    setCursorOffset(offset);
}

// move the cursor to a given position
void screen_moveCursor(u8 row, u8 col)
{
    setCursorOffset(getOffset(row, col));
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
    setCursorOffset(0);
}

void screen_scroll(u8 rows)
{
    for (u8 i=0; i<rows; i++) {
        // put lines back
        memcpy(
            (char *) VIDEO_ADDRESS,
            (char *) VIDEO_ADDRESS+2*MAX_COLS,
            (MAX_ROWS-1)*MAX_COLS*2
        );

        // delete last line
        memset(
            (char *)VIDEO_ADDRESS+2*MAX_COLS*(MAX_ROWS-1),
            0,
            2*MAX_COLS
        );

        // set offset one row back
        setCursorOffset(getCursorOffset() - MAX_COLS*2);
    }
}


/// private functions ///////////////////////

// get the offset of a given position
u16 getOffset(u8 row, u8 col)
{
    return (row * MAX_COLS + col) * 2;
}

u8 getOffsetRow(u16 offset)
{
    return offset/(2*MAX_COLS);
}

u8 getOffsetCol(u16 offset)
{
    return (offset-(getOffsetRow(offset)*2*MAX_COLS))/2;
}

// get the cursor offset
u16 getCursorOffset()
{
    u16 offset;

    // cursor high u8
    port_byteOut(VGA_REG_INDEX, 0x0E);
    offset = port_byteIn(VGA_REG_DATA) << 8;

    // cursor low u8
    port_byteOut(VGA_REG_INDEX, 0x0F);
    offset |= port_byteIn(VGA_REG_DATA);

    return offset * 2;
}

// set the cursor offset
void setCursorOffset(u16 offset)
{
    offset /= 2;

    // cursor high u8
    port_byteOut(VGA_REG_INDEX, 0x0E);
    port_byteOut(VGA_REG_DATA, offset>>8);

    // cursor low u8
    port_byteOut(VGA_REG_INDEX, 0x0F);
    port_byteOut(VGA_REG_DATA, offset);
}
