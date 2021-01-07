#include "libmx.h"

char *mx_strcat(char *restrict s1, char const *restrict s2) {
    int length = mx_strlen(s1);

    mx_strcpy(&s1[length], s2);
    return s1;
}
