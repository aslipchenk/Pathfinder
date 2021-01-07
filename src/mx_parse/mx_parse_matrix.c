#include "pathfinder.h"

void mx_parse_matrix(int argc, char *argv[], s_path *path) {
    path->matrix = (long**) malloc(sizeof(long *) * path->num_of_islands);
    path->array_of_path = (t_arr ***) malloc(sizeof(t_arr **) * (path->num_of_islands + 1));
 
    int i = 0;
    int j = 0;
    int count_parse_island = 0;

    for (i = 0; i < path->num_of_islands; i++) {
        path->matrix[i] = (long *) malloc(sizeof(long) * path->num_of_islands);
        path->array_of_path[i] = (t_arr **) malloc(sizeof(t_arr *) * (path->num_of_islands + 1));
        for (j = 0; j <  path->num_of_islands; j++) {
            path->array_of_path[i][j] = (t_arr *) malloc(sizeof(t_arr) * (path->num_of_islands + 1));
            if (i == j)
                path->matrix[i][j] = 0;
            else 
                path->matrix[i][j] = INT_MAX;
        }
    }
    path->parse_islands_matrix = (char ***) malloc(sizeof(char**) * (path->num_of_islands + 1));
    for (i = 0; i < path->num_of_islands; i++) {
        path->parse_islands_matrix[i] = (char **) malloc(sizeof(char *) * (path->num_of_islands + 1));
        for (j = 0; j < path->num_of_islands; j++) {
            path->parse_islands_matrix[i][j] = mx_strjoin(mx_strjoin(path->parse_islands[i], "-"), path->parse_islands[j]);
            path->array_of_path[i][j]->path = mx_strjoin(mx_strjoin(path->parse_islands[i], " -> "), path->parse_islands[j]);
        }
        path->parse_islands_matrix[i][j] = NULL;
    }
    path->parse_islands_matrix[i] = NULL;

    i = 0;
    while (mx_isdigit(path->str[i++]));
    for (j = 0;path->str[i]; i++) {
            j++;
    }
    path->parse_str = mx_strnew(j);
    i = 0;
    while (mx_isdigit(path->str[i++]));
    for (j = 0; path->str[i]; i++) {
        path->parse_str[j++] = path->str[i];
    }
    path->parse_str = mx_replace_substr(path->parse_str, ",", "-");
    path->parse_str_split = mx_strsplit(mx_replace_substr(path->parse_str, "\n", "-"), '-');

    for (count_parse_island = 0; path->parse_str_split[count_parse_island]; count_parse_island++);
    for (i = 0; i < path->num_of_islands; i++) {
        for (j = 0; j < path->num_of_islands; j++) {
            for (int key = 0; key < count_parse_island - 2; key++) {
                if (i == j)  {
                    path->matrix[i][j] = 0;
                }
                else if (((mx_strcmp(path->parse_str_split[key], mx_before_strchr(path->parse_islands_matrix[i][j], '-')) == 0) && 
                    (mx_strcmp(path->parse_str_split[key + 1], mx_strchr(path->parse_islands_matrix[i][j], '-')) == 0)) || 
                    ((mx_strcmp(path->parse_str_split[key + 1], mx_before_strchr(path->parse_islands_matrix[i][j], '-')) == 0) && 
                    mx_strcmp(path->parse_str_split[key], mx_strchr(path->parse_islands_matrix[i][j], '-')) == 0)) {
                    path->matrix[i][j] = mx_atoi(path->parse_str_split[key + 2]);
                } 
            }
        }
    }
}
