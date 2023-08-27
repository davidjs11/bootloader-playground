#include "utils.h"

// poor implementation of memcpy function
void memcpy(void *dest, void *src, unsigned int n)
{
    for (int i=0; i<n; i++)
        *((char *)dest+i) = *((char *)src+i);
}
