#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    char *dst = (char *) s;
    size_t size;

    if (!s)
        return NULL;
    size = mx_strlen(dst);
    for ( ; size > 0 && n > 0; n--, size--)
        if (dst[size] == c)
            return (void *) &dst[size];
    return NULL;
}
