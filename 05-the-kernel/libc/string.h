#ifndef STRING_H
#define STRING_H

#include "types.h"


/// public functions ////////////////////////

// reverse a string
char *str_reverse(char *str);

// integer to ascii
char *itoa(int val, char *str);

// get lenght of a string
int str_len(const char *str);

// append two strings
char *str_append(char *a, char *b);

// delete last char from string
char *str_backspace(char *str);

// compare two strings
int str_cmp(const char *a, const char *b);


#endif  // STRING_H
