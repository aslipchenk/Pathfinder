#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned long i;
    char *src_char = (char *)src;
    char *dest_char = (char *) dst;

    for (i = 0; i < n; i++)
        dest_char[i] = src_char[i];
    return dst;
}
