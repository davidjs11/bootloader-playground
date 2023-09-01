/// keyboard.c //////////////////////////////

#include "keyboard.h"
#include "string.h"
#include "mem.h"
#include "idt.h"
#include "isr.h"
#include "screen.h"
#include "ports.h"


/// constants ///////////////////////////////

#define BACKSPACE   0x0E
#define ENTER       0x1C
#define MAX_SC      57

const char *sc_name[] = {
    "error", "esc", "1", "2", "3", "4", "5", "6", 
    "7", "8", "9", "0", "-", "=", "backspace",
    "tab", "q", "w", "e", "r", "t", "y", "u", "i",
    "o", "p", "[", "]", "enter", "lctrl", "a", "s",
    "d", "f", "g", "h", "j", "k", "l", ";", "'",
    "`", "lshift", "\\", "z", "x", "c", "v", "b",
    "n", "m", ",", ".", "/", "rshift", "keypad *",
    "lalt", "spacebar"};

const char sc_ascii[] = {
    '?', '?', '1', '2', '3', '4', '5', '6',     
    '7', '8', '9', '0', '-', '=', '?', '?',
    'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I',
    'O', 'P', '[', ']', '?', '?', 'A', 'S',
    'D', 'F', 'G', 'H', 'J', 'K', 'L', ';',
    '\'','`', '?', '\\','Z', 'X', 'C', 'V',
    'B', 'N', 'M', ',', '.', '/', '?', '?',
    '?', ' '
};

char keybuffer[256];


/// functions ///////////////////////////////

void keyboard_callback(registers_t regs)
{
    // get scancode
    u8 scancode = port_byteIn(0x60);
    itoa(scancode, (char *) sc_ascii);

    if (scancode > MAX_SC) return;

    if (scancode == BACKSPACE) {
        screen_deletelast();
        str_backspace(keybuffer);
    }

    else if (scancode == ENTER) {
        screen_print("\n> ", 0x0A);

        // check command
        if (!str_cmp(keybuffer, "HALT")) {
            screen_clear();
            screen_print("SHUTING DOWN CPU... SEE YOU SOON!", 0x0A);
            __asm__("hlt");
        }

        // reset keybuffer 
        memset(keybuffer, 0x00, 256);
    }

    else {
        // insert letter into buffer
        char letter = sc_ascii[scancode];
        keybuffer[str_len(keybuffer)] = letter;

        // print letter
        char str[2] = {letter, 0x00};
        screen_print(str, 0x0A);
    }
}

void keyboard_init()
{
    screen_print("initializing keyboard...\n", 0x0A);
    register_interrupt_handler(IRQ1, keyboard_callback);
}
