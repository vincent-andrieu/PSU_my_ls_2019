/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** header
*/

#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>

#ifndef MY_LS_H_
#define MY_LS_H_

#define EXIT_ERROR 84

typedef struct options_s
{
    bool l;
    bool ur;
    bool d;
    bool r;
    bool t;
    bool a;
} options_t;

typedef struct file_s
{
    char *name;
    struct stat st;
    struct file_s *next;
} file_t;

int my_ls(int argc, char **argv);
options_t *get_flags(int argc, char **argv);
void do_flags(options_t *options, char **argv, int argc, bool multi_files);
file_t *get_files(char *path, options_t *options);
void flag_l(options_t *options, char *argv);
void put_total_l(char *path, file_t *files);
void put_details(file_t *files, int sp_nlinks, int sp_size);
int get_num_nbr(int nbr);
file_t *my_rev_list(file_t *first, file_t *files, file_t *prev);
void free_files(file_t *file);
void basic_ls(options_t *options, char *argv);
void flag_d(options_t *options, char **argv, int argc);
void flag_ur(options_t *options, char **paths);
char *get_filepath(char *path, char *name);
file_t *swap_files(file_t *files, file_t *last);
file_t *sort_time(file_t *first, file_t *files, file_t *last);

#endif