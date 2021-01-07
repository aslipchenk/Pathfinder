#include "pathfinder.h"

void mx_all_errors(int argc, char *argv[], s_path *path) {
    mx_invalid_number_args(argc, argv, path);
    if (!path->error_flag)
        mx_does_not_exist(argc, argv, path);
    if (!path->error_flag)
        mx_is_empty(argc, argv, path);
    if (!path->error_flag)
        mx_first_line_not_valid(argc, argv, path);
    if (!path->error_flag)
        mx_line_is_not_valid(argc, argv, path);
    if (!path->error_flag)
        mx_invalid_num_of_islands(argc, argv, path);
    if (!path->error_flag)
        mx_duplicate_bridges(argc, argv, path);
    if (!path->error_flag)
        mx_sum_length_error (argc, argv, path);
}
