#ifndef UTIL
#define UTIL

/// type definition /////////////////////////
typedef unsigned char   u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef char i8;
typedef short i16;
typedef int i32;

/// functions ///////////////////////////////
void memcpy(void *dest, void *src, unsigned int n);
void memset(void *dest, char value, unsigned int n);

#endif  // UTILS
