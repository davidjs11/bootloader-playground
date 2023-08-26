/// kernel.c ////////////////////////////////

// print a string into the vga text buffer
void print_vga(char *buffer, const char *val) {
    // print until last character
    while(*val != 0) {
        *buffer = *val;
        buffer += 2;
        val++;
    }
}

void main() {
    char *videoMemory = (char *) 0xB8000;
    print_vga(videoMemory, "kernel.c loaded successfully");
}
