#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *temp = mx_strtrim(str);
    char *dst = NULL;
    int size = 0;
    int j = 0;
    int i = 0;

    if (!temp)
        return mx_strdup("\0");
    for (i = 0; temp[i++]; size++)
        while (mx_isspace(temp[i++]));
    dst = mx_strnew(size);
    for (i = 0; temp[i]; i++) {
        if(mx_isspace(temp[i]))
            while (mx_isspace(temp[i + 1]))
                temp[++i] = ' ';
        dst[j++] = temp[i];
    }
    mx_strdel(&temp);
    return dst;
}
