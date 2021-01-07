#include "libmx.h"

char *mx_strchr (char *str, char c) {
    if (!str || !c)
        return NULL;
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return &str[++i];
    }
    return NULL;
}
