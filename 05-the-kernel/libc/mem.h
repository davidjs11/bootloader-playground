#ifndef MEM_H
#define MEM_H

#include "types.h"


/// public functions ////////////////////////

// copy a memory block of size 'n' in a selected position
void memcpy(void *dest, void *src, unsigned int n);

// set 'n' bytes of a memory block to a selected 'value'
void memset(void *dest, char value, unsigned int n);


#endif
