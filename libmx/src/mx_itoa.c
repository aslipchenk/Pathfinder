#include "libmx.h"

char *mx_itoa (int number) {
    char *string = NULL;
    int length = 0;
    bool flag = false;

    if (number < 0 && number != INT_MIN) {
        number *= -1;
        flag = true;
        length++;
    } else if (number == INT_MIN)
        return mx_strdup("-2147483648");
    if (number == 0) 
        return mx_strdup("0"); 
    for (int temp = number; temp; length++)
        temp = temp / 10;
    string = mx_strnew(length);
    for (; number; number /= 10) 
        string[--length] = number % 10 + 48;
    if (flag)
        string[0] = '-';  
    return string; 
} 
