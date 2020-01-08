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

void do_flags(options_t *options, char **argv, int argc, bool multi_files)
{
    if (options->d) {
        flag_d(options, argv, argc);
        return;
    }
    if (multi_files) {
        my_putstr(argv[options->r ? argc : 0]);
        my_putstr(":\n");
    }
    if (options->R)
        flag_ur(options, argv);
    else if (options->l)
        flag_l(options, argv[options->r ? argc : 0]);
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

int my_ls(int argc, char **argv)
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