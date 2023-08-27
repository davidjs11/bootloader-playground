#ifndef UTIL_H
#define UTIL_H

/// bitwise operations utilities ////////////
#define LOWEST16(val)(val&0xFFFF)
#define HIGHEST16(val)((val>>16)&0xFFFF)

#include "types.h"

/// memory blocks ///////////////////////////
void memcpy(void *dest, void *src, unsigned int n);
void memset(void *dest, char value, unsigned int n);

/// strings /////////////////////////////////
char *str_reverse(char *str);
char *itoa(int val, char *str);

#endif  // UTILS_H
