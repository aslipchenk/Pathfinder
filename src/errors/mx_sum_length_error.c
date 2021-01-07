#include "pathfinder.h"

void mx_sum_length_error (int argc, char *argv[], s_path *path) {
    int count_num = 0;
    int i = 0;
    int j = 0;
    int temp = 0;
    path->sum_of_length = 0;

    while(mx_isdigit(path->str[i++]));
    for (; path->str[i]; i++) {
        if (mx_isdigit(path->str[i])) {
            while (mx_isdigit(path->str[i])) {
                i++;
            }
            count_num++;
        }
    }
    path->arr_digits = (int *) malloc(sizeof(int *) * count_num);
    i = 0;
    while(mx_isdigit(path->str[i++]));
    for(; path->str[i]; i++) {
        if (mx_isdigit(path->str[i])) {
            while (mx_isdigit(path->str[i])) {
                temp *= 10;
                temp += (path->str[i] - 48);
                i++;
            }
            path->arr_digits[j] = temp;
            temp = 0;
            j++;
        }
    }
    for (i = 0; i < j; i++) {
        path->sum_of_length += path->arr_digits[i];
        if (path->sum_of_length > INT_MAX) {
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(1);
        }
    }
}
