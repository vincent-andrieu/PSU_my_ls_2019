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
    bool R;
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
    struct file_s *prev;
} file_t;

options_t *get_flags(int argc, char **argv);
void flag_l(options_t *options, char **argv, int argc);
file_t *get_files(char *path, bool get_allfiles);
void put_total_l(file_t *files);
void put_details(file_t *files, int sp_nlinks, int sp_size);
int get_num_nbr(int nbr);

#endif