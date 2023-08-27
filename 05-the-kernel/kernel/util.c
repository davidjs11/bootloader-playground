#include "util.h"

/// public functions ////////////////////////

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

// reverse a string
char *str_reverse(char *str)
{
    // get lenght of string
    int len = 0;
    while(*(str+len)) len++;

    // reverse the string
    for(int i=0, tmp; i < len/2; i++) {
        tmp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = tmp;
    }

    return str;
}

// poor int to ascii converter
char *itoa(int value, char *str)
{
    int i, sign;
    if ((sign = value) < 0) value = -value;

    for(i = 0; value>0; value/=10)
        str[i++] = value % 10 + '0';

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';

    return str_reverse(str);
}
