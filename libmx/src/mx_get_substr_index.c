#include "libmx.h"

int mx_get_substr_index (const char *str, const char *sub) {
    int index = 0;

    if (!str || !sub)
        return -2;
    for (; str[index]; index++) {
        if (mx_strncmp(&str[index], sub, mx_strlen(sub)) == 0)
            return index;
    }
    return -1;
}
