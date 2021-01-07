#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    char *dst = (char *) s;

    for (size_t i = 0; i < n && dst[i]; i++) 
        if (dst[i] == c)
            return (void *) &dst[i];
    return NULL;
}
