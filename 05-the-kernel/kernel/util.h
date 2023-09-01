/// util.h //////////////////////////////////

#ifndef UTIL_H
#define UTIL_H

#include "types.h"


/// bitwise operation utilities /////////////

#define LOWEST16(val)(val&0xFFFF)
#define HIGHEST16(val)((val>>16)&0xFFFF)
#define LOWEST8(val)(val&0xFF)
#define HIGHEST8(val)((val>>8)&0xFF)


#endif  // UTILS_H
