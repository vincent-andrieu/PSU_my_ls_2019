/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** recode ls
*/

#include <dirent.h>
#include <sys/sysmacros.h>
#include "my.h"
#include "my_ls.h"

static void basic_ls(options_t *options, char *argv)
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

static void do_flags(options_t *options, char **argv, int argc,
                    bool multi_files)
{
    if (multi_files) {
        my_putstr(argv[options->r ? argc : 0]);
        my_putstr(":\n");
    }
    if (options->l)
        flag_l(options, argv[options->r ? argc : 0]);
    else if (options->R)
        my_putchar('#');
    else
        basic_ls(options, argv[options->r ? argc : 0]);
    if (argc > 0) {
        my_putchar('\n');
        argv += !options->r;
        do_flags(options, argv, --argc, multi_files);
    }
}

void free_files(file_t *file)
{
    if (file == NULL)
        return;
    free_files(file->next);
    free(file->name);
    free(file);
}

int main(int argc, char **argv)
{
    int i = 1;
    options_t *options = get_flags(argc, argv);

    argv++;
    argc--;
    for (; i <= argc && argv[0][0] == '-'; i++, argv++);
    if (i > argc) {
        argv--;
        argc = 0;
        argv[0][0] = '.';
        argv[0][1] = '\0';
    } else
        argc -= i;
    do_flags(options, argv, argc, argc > 0);
    free(options);
    return EXIT_SUCCESS;
}