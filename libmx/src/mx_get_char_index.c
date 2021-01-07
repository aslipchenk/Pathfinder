#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
    int index = 0;

    if (str == NULL)
        return -2;
    for(index = 0; str[index] != c; index++) 
        if (!str[index + 1])
            return -1; 
    return index;
}
