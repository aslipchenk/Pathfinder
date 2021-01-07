#include "pathfinder.h"

void mx_parse_islands(int argc, char *argv[], s_path *path) {
    int j = 0;
    int count = 0;
    int i = 0;
    bool flag = false;
   
    path->parse_islands = (char **)malloc(sizeof(char *) * (path->num_of_islands + 1));
    for (i = 0; path->temp_trim[i]; i++)
        if (mx_isalpha(path->temp_trim[i]))
            j++;
    j = mx_count_substr(path->temp_trim, "-");
    for (i = 0; i < j - 1; i++) {
        flag = false;
        for (int key = 0; key < i; key++) 
            if (mx_strcmp(path->str_split_by_def[key], path->str_split_by_def[i]) == 0) 
                flag = true;
        if (!flag) {
            path->parse_islands[count] = mx_strdup(path->str_split_by_def[i]);
            count++;
        }
    }
    path->parse_islands[count] = NULL;
}

