#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, 
                const void *little, size_t little_len) {
    if (!big || !big_len || !little || !little_len)
        return NULL;
    for(const char *dst = big; big_len >= little_len; dst++, big_len--)
        if (!mx_memcmp(dst, little, little_len)) 
            return (void *) dst;
    return NULL;
}
