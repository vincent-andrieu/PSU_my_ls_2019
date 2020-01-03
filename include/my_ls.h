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
char const *months_name[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
                            "Aug", "Sept", "Oct", "Nov", "Dec"};

typedef struct options_s
{
    bool l;
    bool R;
    bool d;
    bool r;
    bool t;
} options_t;

typedef struct file_s
{
    char *name;
    struct stat st;
} file_t;

options_t *get_flags(int argc, char **argv);
void flag_l(options_t *options, char **argv, int argc);

#endif