#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    char *new_s1 = (char *) s1;
    char *new_s2 = (char *) s2;

    if (n == 0)
        return 0;
    while(n > 1 && *new_s1 == *new_s2 && *new_s1 && *new_s2) {
        n--;
        new_s1++;
        new_s2++;
    }
    return (unsigned char) *new_s1 - (unsigned char) *new_s2;  
}
