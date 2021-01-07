#include "libmx.h"

bool mx_isalpha(int c) {
    if ((c <= 90 && c >= 65) || (c >= 97 && c <= 122)) {
        return 1;
}
    return 0; 
}
