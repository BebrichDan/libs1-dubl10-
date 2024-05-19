#include "library.h"

#include <stdio.h>

void hello(void)
{
    printf("Hello, World!\n");
}

size_t strlen_(char *begin) {
    char *end = begin;
    while (*end != '\0')
        end += sizeof(char);
    return end - begin;
}