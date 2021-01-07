#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int count = 0;
    int temp = 0;
    int i = 0;

    if (!str)
        return -1; 
    for(i = 0; str[i] != '\0'; i++) {
        if (str[i] != c)
            temp = 1;
        if (str[i] == c && temp) {
            temp = 0;
            count++;
    }
}
    if (str[i-1] != c)
        count++;
    return count;
}
