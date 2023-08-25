/// kernel.c ////////////////////////////////

// function test
void function(char *ptr, char val)
{
    *ptr = val;
}

// main program
void main()
{
    // Display '!' as the first character in the screen
    char *videoMemory = (char *) 0xB8000;
    function(videoMemory, '!');
}
