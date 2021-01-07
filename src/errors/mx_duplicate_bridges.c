#include "pathfinder.h"

void mx_duplicate_bridges(int argc, char *argv[], s_path *path) {
    int j = 0;

    for (int i = 0; path->str[i]; i++)
        if(mx_isalpha(path->str[i]) || path->str[i] == '\n' || 
             path->str[i] == '-') 
            j++;
    path->temp_trim_dup_bridge = mx_strnew(j);
    j = 0;
    for (int i = 0; path->str[i]; i++)
        if(mx_isalpha(path->str[i]) || path->str[i] == '\n' || 
             path->str[i] == '-') { 
            path->temp_trim_dup_bridge[j] = path->str[i]; 
            j++;
            }
    path->temp_trim_dup_bridge = mx_replace_substr(path->temp_trim_dup_bridge, "\n", "-");
    j = mx_count_substr(path->temp_trim_dup_bridge, "-");
    path->str_split_by_def = mx_strsplit(path->temp_trim_dup_bridge, '-');
    for (int i = 0; i < j - 3; i += 2) {
        if (((mx_strcmp(path->str_split_by_def[i], path->str_split_by_def[i + 2]) == 0) &&
            (mx_strcmp(path->str_split_by_def[i + 1], path->str_split_by_def[i + 3]) == 0)) ||
            ((mx_strcmp(path->str_split_by_def[i], path->str_split_by_def[i + 3]) == 0) &&
            (mx_strcmp(path->str_split_by_def[i + 1], path->str_split_by_def[i + 2]) == 0))) {
                mx_printerr("error: duplicate bridges\n");
                exit(1);
        }
    }   
}
