/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** flags
*/

#include "my.h"
#include "my_ls.h"

void basic_ls(options_t *options, char *argv)
{
    file_t *files = get_files(argv, options);
    file_t *first_files = files;

    for (; files != NULL; files = files->next) {
        if (files != first_files)
            my_putstr("  ");
        my_putstr(files->name);
    }
    free_files(first_files);
    my_putchar('\n');
}

void flag_d(options_t *options, char **argv, int argc)
{
    bool first = true;

    for (int i = options->r ? argc : 0; options->r ? i >= 0 : i <= argc;
    i += options->r ? -1 : 1) {
        if (!first)
            my_putstr("  ");
        first = false;
        my_putstr(argv[i]);
    }
    my_putchar('\n');
}

void flag_ur(options_t *options, char **paths)
{
    file_t *files = get_files(paths[0], options);
    file_t *first = files;

    my_putstr(paths[0]);
    my_putstr(":\n");
    options->R = false;
    do_flags(options, paths, 0, false);
    options->R = true;
    for (char *filepath[1]; files != NULL; files = files->next)
        if (S_ISDIR(files->st.st_mode)) {
            filepath[0] = get_filepath(paths[0], files->name);
            my_putchar('\n');
            flag_ur(options, filepath);
            free(filepath[0]);
        }
    free_files(first);
}