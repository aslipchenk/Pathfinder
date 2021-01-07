#include "pathfinder.h"

void mx_invalid_num_of_islands(int argc, char *argv[], s_path *path) {
    int j = 0;
    path->count_islands = 1;

    for (int i = 0; path->str[i]; i++)
        if(mx_isalpha(path->str[i]) || path->str[i] == '\n' || 
            path->str[i] == '-') {
            j++;
        }
    path->temp_trim = mx_strnew(j);
    j = 0;
     for (int i = 0; path->str[i]; i++)
        if(mx_isalpha(path->str[i]) || path->str[i] == '\n' || 
            path->str[i] == '-') {
            path->temp_trim[j] = path->str[i];
            j++;
        }
    path->temp_trim = mx_replace_substr(path->temp_trim, "\n", "-");
    j = mx_count_substr(path->temp_trim, "-");
    path->str_split_by_def = mx_strsplit(path->temp_trim, '-');
    mx_bubble_sort(path->str_split_by_def, --j);
    for (int i = 0; i < j - 1; i++) 
        if(mx_strcmp(path->str_split_by_def[i], path->str_split_by_def[i + 1]))
            path->count_islands++;
    if (path->count_islands != path->num_of_islands) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
}
