#include <stdbool.h>

bool mx_isdigit(int c) {
    if (c <= 57 && c >= 48) {
        return 1;
    }
    return 0;
}
