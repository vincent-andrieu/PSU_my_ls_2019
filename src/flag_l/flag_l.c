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
    for (int dix = 10; dix <= nbr && n < 10; n++, dix *= 10);
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

void put_total_l(char *path, file_t *files)
{
    int total = 0;
    struct stat st;

    lstat(path, &st);
    if (!S_ISDIR(st.st_mode))
        return;
    for (; files != NULL; files = files->next)
        total += files->st.st_blocks / 2;
    my_putstr("total ");
    my_put_nbr(total);
    my_putchar('\n');
}

void flag_l(options_t *options, char *argv)
{
    char *path = my_strdup(argv);
    file_t *files = get_files(argv, options);
    file_t *first_file = files;
    int sp_nlinks = get_sp_nlinks(files);
    int sp_size = get_sp_size(files);

    put_total_l(path, files);
    free(path);
    for (; files != NULL; files = files->next)
        put_details(files, sp_nlinks, sp_size);
    free_files(first_file);
}