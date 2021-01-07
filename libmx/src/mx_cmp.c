#include "libmx.h"

bool mx_cmp(void *a, void *b) {
    if (a > b)
        return true;
    return false;
}
