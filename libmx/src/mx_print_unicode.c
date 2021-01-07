#include "libmx.h"

void mx_print_unicode(wchar_t c) {
    int arr[4] = {0};

    if (c >= 1112065)
        return;
    if (c < 128)
        mx_printchar(c);
    else {
        for (int i = 0 ; i < 4; i++) {
            arr[i] = 128 | (63 & (c >> (6 * i)));
            if (!(c >> (6 + 5 * i)) && i > 0) {
                arr[i] = (256 - (128 >> i)) | (c >> (6 * i));
                for( ; i >= 0; i--) 
                    write(1, &arr[i], 1);
                return;
            }
        }
    }
}
