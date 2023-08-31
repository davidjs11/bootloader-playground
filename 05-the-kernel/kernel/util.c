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

    for (i=0; value>0; value/=10)
        str[i++] = value % 10 + '0';

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';

    return str_reverse(str);
}

// get the lenght of a string
int str_len(const char *str)
{
    int len = 0;
    while (str[len]) len++;
    return len;
}

// append two strings
char *str_append(char *a, char *b)
{
    int i = str_len(a);
    while (*b) a[i++] = *(b++);

    return a;
}

// delete last character
char *str_backspace(char *str)
{
    str[str_len(str)-1] = 0;
    return str;
}

// compare two strings
int str_cmp(const char *a, const char *b)
{
    while (*a && *b) {
        if (*a != *b) break;
        a++;
        b++;
    }

    return (*(a) - *(b));
}
