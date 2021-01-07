#include "pathfinder.h"

static void printerr(int *i) {
    mx_printerr("error: line ");
    *i = *i + 1;
    mx_printerr(mx_itoa(*i));
    mx_printerr(" is not valid\n");
    exit(1);
}

void mx_line_is_not_valid (int argc, char *argv[], s_path *path) {
    path->str_split = mx_strsplit(path->str, '\n');

    for (int i = 1; path->str_split[i]; i++) {
        for (int j = 0; j < mx_strlen(path->str_split[i]); j++) {
            if (path->str_split[i][j] == '-')  {
                if (mx_strncmp(path->str_split[i], &path->str_split[i][j + 1], 
                    j) == 0)
                    printerr(&i);
                j++;
            }
            if (path->str_split[i][j] != ',' && 
                !mx_isalpha(path->str_split[i][j]))
                printerr(&i);
            if (path->str_split[i][j] == ',') {
                if (!(mx_isdigit(path->str_split[i][j + 1]))) 
                     printerr(&i);
                 while (path->str_split[i][++j]) 
                    if (!mx_isdigit(path->str_split[i][j])) 
                        printerr(&i);
            }
        }
    }
}
