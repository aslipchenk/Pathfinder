#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char *arr = NULL;
    unsigned long temp = nbr;
    int j = 0;

    if (nbr == 0) 
        return mx_strdup("0");
    for (; nbr != 0; j++) 
        nbr = nbr/16;
    arr = mx_strnew(j);
    for (unsigned long i = 0; temp != 0; i++) {
        (temp % 16 < 10) ? (arr[--j] = temp % 16 + 48) 
                         : (arr[--j] = temp % 16 + 87);
        temp = temp / 16;
    }
    return arr;
}
