#include "libmx.h"

char *mx_before_strchr (char *str, char c) {
    char *temp;

    if (!str || !c)
        return NULL;
    temp = mx_strnew(mx_get_char_index(str, c));
    if (!temp)
        return NULL;
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return temp;
        temp[i] = str[i];
    }
    return NULL;
}
