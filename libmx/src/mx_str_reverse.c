#include "libmx.h"

void mx_str_reverse (char *s) {
    int length = 0;

    if (s == NULL)
        return;
    length = mx_strlen(s) - 1;
    for (int i = 0; i < length; i++) {
        mx_swap_char(&s[i], &s[length]);
        length--;
    }
}
