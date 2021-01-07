#include "pathfinder.h"

void mx_main_algoritm(int argc, char *argv[], s_path *path) {
    path->output_matrix = (char***) malloc(sizeof(char **) * (path->num_of_islands + 1));
    long **arr_or = (long **) malloc(sizeof(long *) * path->num_of_islands);
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i < path->num_of_islands; i++) {
        path->output_matrix[i] = (char **) malloc(sizeof(char *) * (path->num_of_islands + 1));
        arr_or[i] = (long *) malloc(sizeof(long ) * path->num_of_islands);
        for (j = 0; j < path->num_of_islands; j++) {
            arr_or[i][j] = path->matrix[i][j];
            path->output_matrix[i][j] = mx_strnew(0);
            if (arr_or[i][j] != INT_MAX && arr_or[i][j] != 0) {
                path->array_of_path[i][j]->buf = mx_strjoin(mx_itoa(i), mx_itoa(j));
                path->output_matrix[i][j] = mx_strdup(path->array_of_path[i][j]->buf);
                }
            else
                path->array_of_path[i][j]->buf = "\0";  
        }
        path->output_matrix[i][j] = NULL;
    }
    path->output_matrix[i] = NULL;
    for (k = 0; k < path->num_of_islands; k++) {
        for (i = 0; i < path->num_of_islands; i++) {
            for (j = 0; j < path->num_of_islands; j++) {
                if (path->matrix[i][j] > path->matrix[i][k] + path->matrix[k][j]) {
                    path->matrix[i][j] = path->matrix[i][k] + path->matrix[k][j];
                    path->array_of_path[i][j]->buf = mx_strjoin(path->array_of_path[i][k]->buf, path->array_of_path[k][j]->buf);
                }
            }
        }
    }
    for (k = path->num_of_islands - 1; k >= 0; k--) {
        for (i = path->num_of_islands - 1; i >= 0; i--) {
            for (j = path->num_of_islands - 1; j >= 0; j--) {
                if (path->matrix[i][j] == path->matrix[i][k] + path->matrix[k][j] && path->matrix[i][k] != 0 && path->matrix[k][j] != 0) {
                    path->array_of_path[i][j]->buf = mx_strjoin(path->array_of_path[i][k]->buf, path->array_of_path[k][j]->buf);
                    if (arr_or[i][j] > path->matrix[i][j] && arr_or[i][j] != INT_MAX)
                        path->output_matrix[i][j] = mx_strdup("\0");
                    if (mx_get_substr_index(path->output_matrix[i][j], path->array_of_path[i][j]->buf) < 0) {
                        if (mx_strcmp(path->output_matrix[i][j], "\0") == 0)
                            path->output_matrix[i][j] = mx_strjoin(path->array_of_path[i][j]->buf, path->output_matrix[i][j]);
                        else if (mx_strcmp(path->output_matrix[i][j], path->array_of_path[i][j]->buf) < 0)
                            path->output_matrix[i][j] = mx_strjoin(path->output_matrix[i][j], mx_strjoin("-", path->array_of_path[i][j]->buf));
                        else if (mx_strcmp(path->output_matrix[i][j], path->array_of_path[i][j]->buf) > 0)
                            path->output_matrix[i][j] = mx_strjoin(mx_strjoin(path->array_of_path[i][j]->buf, "-"), path->output_matrix[i][j]);
                    }
                }
            }
        }
    }
   
}


