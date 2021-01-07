#pragma once

#include "libmx.h"

typedef struct ArrayOfPath
{
    char *path;
    char *route_str;
    char *distance;
    char *buf;
   // t_arr *next;
} t_arr;

typedef struct Alternative_path 
{
    char *path;
    char *route_str;
    char *distance;
} t_alt;


typedef struct Pathfinder {
    unsigned long long sum_of_length;
    long **matrix;
    int *arr_digits;
    int num_of_islands;
    int count_islands;
    char **str_split;
    char **str_split_by_def;
    char **parse_str_split;
    char **parse_islands;
    char ***parse_islands_matrix;
    char ***output_matrix;
    char *parse_str;
    char *str;
    char *temp_trim;
    char *temp_trim_dup_bridge;

    t_alt ***alternative_path;
    t_arr ***array_of_path;
    bool error_flag;
} s_path;



// ERRORS
void mx_invalid_number_args(int argc, char *argv[], s_path *path);
void mx_all_errors(int argc, char *argv[], s_path *path);
void mx_does_not_exist(int argc, char *argv[], s_path *path);
void mx_is_empty(int argc, char *argv[], s_path *path);
void mx_first_line_not_valid(int argc, char *argv[], s_path *path);
void mx_line_is_not_valid (int argc, char *argv[], s_path *path);
void mx_invalid_num_of_islands(int argc, char *argv[], s_path *path);
void mx_duplicate_bridges(int argc, char *argv[], s_path *path);
void mx_sum_length_error (int argc, char *argv[], s_path *path);

//MAIN ALGORITM
void mx_main_algoritm(int argc, char *argv[], s_path *path);

//PARSE
void mx_parse_islands(int argc, char *argv[], s_path *path);
void mx_parse_matrix(int argc, char *argv[], s_path *path);

//OUTPUT
void mx_out(int argc, char *argv[], s_path *path);
