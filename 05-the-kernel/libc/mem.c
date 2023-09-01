#include "mem.h"


// copy memory blocks of size 'n' from 'src' to 'dest'
void memcpy(void *dest, void *src, unsigned int n)
{
    for (int i=0; i<n; i++)
        *((char *)dest+i) = *((char *)src+i);
}

// set 'value' of 'n' memory blocks in 'dest'
void memset(void *dest, char value, unsigned int n)
{
    for (int i=0; i<n; i++)
        *((char *) dest+i) = value;
}
