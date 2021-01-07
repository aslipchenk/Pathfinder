#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *temp = mx_strnew(len); 
  
    mx_memcpy(temp, src, len);
    mx_memcpy(dst, temp, len);
    mx_strdel(&temp);
    return dst;
} 
