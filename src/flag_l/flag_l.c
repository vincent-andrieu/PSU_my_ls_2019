/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** flag l
*/

#include <dirent.h>
#include <sys/sysmacros.h>
#include "my.h"
#include "my_ls.h"

int get_num_nbr(int nbr)
{
    int n = 1;

    nbr = nbr < 0 ? -nbr : nbr;
    for (int dix = 10; dix <= nbr && n < 10; n++)
        dix *= 10;
    return n;
}

static int get_sp_nlinks(file_t *files)
{
    int spaces = 0;

    for (int num; files != NULL; files = files->next) {
        num = get_num_nbr(files->st.st_nlink);
        spaces = num > spaces ? num : spaces;
    }
    return spaces;
}

static int get_sp_size(file_t *files)
{
    int spaces = 0;

    for (int num; files != NULL; files = files->next) {
        num = get_num_nbr(files->st.st_size);
        spaces = num > spaces ? num : spaces;
    }
    return spaces;
}

void flag_l(options_t *options, char *argv)
{
    file_t *files = get_files(argv, options);
    file_t *first_file = files;
    int sp_nlinks = get_sp_nlinks(files);
    int sp_size = get_sp_size(files);

    put_total_l(files);
    for (; files != NULL; files = files->next)
        put_details(files, sp_nlinks, sp_size);
    free_files(first_file);
}