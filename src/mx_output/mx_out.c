#include "pathfinder.h"

static void printDistance (int i, char *index_str, s_path *path, int matr, int reindex) {
    int index = 0;
    int sec = 0;

    mx_printstr("\nDistance: ");
    for (i = reindex; mx_isdigit(index_str[i]); i += 2) {
        index = index_str[i] - 48;
        sec = index_str[i + 1] - 48;
        mx_printint(path->matrix[index][sec]);
        if (mx_isdigit(index_str[i + 2]))
            mx_printstr(" + ");
    }
    if (i - reindex > 2) {
        mx_printstr(" = ");
        mx_printint(matr);
    }
    mx_printchar('\n');
    mx_printstr("========================================\n");
}

static void printAll(int i, char *index_str, s_path *path, char *path_str, int matr) {
    int index = 0;
    int reindex = i;
    int sec = 0;

    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(path_str);
    mx_printchar('\n');
    mx_printstr("Route: ");
    for ( ; mx_isdigit(index_str[i]); i++) {
        if (index_str[i] != index_str[i + 1]) {
            index = index_str[i] - 48;
            mx_printstr(path->parse_islands[index]);
            if (mx_isdigit(index_str[i + 1]))
                    mx_printstr(" -> ");
        }
    }
    mx_printstr("\nDistance: ");
    for (i = reindex; mx_isdigit(index_str[i]); i += 2) {
        index = index_str[i] - 48;
        sec = index_str[i + 1] - 48;
        mx_printint(path->matrix[index][sec]);
        if (mx_isdigit(index_str[i + 2]))
            mx_printstr(" + ");
    }
    if (i - reindex > 2) {
        mx_printstr(" = ");
        mx_printint(matr);
    }
    mx_printchar('\n');
    mx_printstr("========================================\n");
    // printDistance(i, index_str, path, matr, reindex);
    if(index_str[i]) 
        printAll(i + 1, index_str, path, path_str, matr);
}

void mx_out(int argc, char *argv[], s_path *path) {
    for (int i = 0; i < path->num_of_islands; i++) {
        for (int j = i; j < path->num_of_islands; j++) {
            if (j != i) {
                printAll(0, path->output_matrix[i][j], path, 
                path->array_of_path[i][j]->path, path->matrix[i][j]);
            }
        }
    }
    return;
}

