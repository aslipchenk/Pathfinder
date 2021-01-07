#include "pathfinder.h"

void mx_invalid_number_args(int argc, char *argv[], s_path *path) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        path->error_flag = true;
    }
}
