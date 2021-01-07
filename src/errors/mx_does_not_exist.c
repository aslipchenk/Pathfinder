#include "pathfinder.h"

void mx_does_not_exist(int argc, char *argv[], s_path *path) {
    path->str = mx_file_to_str(argv[1]);
    
    if (!path->str) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n"); 
        path->error_flag = true;
    }
}
