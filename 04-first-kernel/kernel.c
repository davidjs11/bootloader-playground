/// kernel.c ////////////////////////////////

void main()
{
    // Display '!' as the first character in the screen
    char *videoMemory = (char *) 0xB8000;
    *videoMemory = '!';
}
