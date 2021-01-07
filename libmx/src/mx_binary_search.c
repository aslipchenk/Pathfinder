#include "libmx.h"

int mx_binary_search (char **arr, int size, const char *s, int *count) {
    int lower = 0;
    int upper = size - 1;
    int mid = 0;
    int res = -1;

    while (lower <= upper) {
        (*count)++;
        mid = lower + (upper - lower) / 2;
        if (mx_strcmp(arr[mid], s) == 0)
            return mid;
        if (mx_strcmp(arr[mid], s) < 0)
            lower = mid + 1;
        else 
            upper = mid - 1;
    }
    (*count) = 0;
    return res;
}
