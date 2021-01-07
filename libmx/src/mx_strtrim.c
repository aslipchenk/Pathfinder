#include "libmx.h"

char *mx_strtrim(const char *str) {
    int i = 0;
    int size = 0;
    char *dst = NULL;

    if (!str)
        return NULL;
    size = mx_strlen(str);
    while (mx_isspace(str[i])) {
        i++;
        if (!str[i+1])
            return NULL;
    }
    while (mx_isspace(str[--size]));
    size = size - i + 1;
    dst = mx_strnew(size);
    mx_strncpy(dst, &str[i++], size);
    return dst;
}
