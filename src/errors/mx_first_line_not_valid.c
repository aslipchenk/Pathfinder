#include "pathfinder.h"

void mx_first_line_not_valid(int argc, char *argv[], s_path *path) {
    char *temp_str = mx_strnew(mx_get_char_index(path->str, '\n'));
    path->num_of_islands = 0;

    for (int i = 0; path->str[i] != '\n'; i++) {
        temp_str[i] = path->str[i];
        if (mx_isalpha(path->str[i])) {
            mx_printerr("error: line 1 is not valid\n");
            path->error_flag = true;
            return;
        }
    }
    path->num_of_islands = mx_atoi(temp_str);
    if (path->num_of_islands < 0) {
        mx_printerr("error: line 1 is not valid\n");
        path->error_flag = true;
    }
}
