#include "pathfinder.h"

void mx_is_empty(int argc, char *argv[], s_path *path) {
    if (mx_strtrim(path->str) == NULL) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n"); 
        path->error_flag = true;
    }
}
