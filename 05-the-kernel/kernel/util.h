#ifndef UTIL_H
#define UTIL_H

/// bitwise operations utilities ////////////
#define LOWEST16(val)(val&0xFFFF)
#define HIGHEST16(val)((val>>16)&0xFFFF)

#include "types.h"

/// functions ///////////////////////////////
void memcpy(void *dest, void *src, unsigned int n);
void memset(void *dest, char value, unsigned int n);

#endif  // UTILS_H
