#include "pathfinder.h"

int main (int argc, char *argv[]) {
    s_path *path = malloc(sizeof(s_path));
    mx_all_errors(argc, argv, path);
    if (!path->error_flag) {
        mx_parse_islands(argc, argv, path);
        mx_parse_matrix(argc, argv, path);
        mx_main_algoritm(argc, argv, path);
        mx_out(argc, argv, path); 
    }
    if (path->error_flag) 
        return 0;
    return 0;
}
