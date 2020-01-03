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

static void do_flags(options_t *options, char **argv, int argc)
{
    if (options->l)
        flag_l(options, argv, argc);
}

int main(int argc, char **argv)
{
    int i = 1;
    options_t *options = get_flags(argc, argv);

    argv++;
    argc--;
    for (; i <= argc && argv[0][0] == '-'; i++, argv++)
        printf("%d %d\n", i, argc);
    if (i > argc) {
        argv--;
        argc = 1;
        argv[0][0] = '.';
        argv[0][1] = '\0';
    } else
        argc -= i;
    do_flags(options, argv, argc);
    return EXIT_SUCCESS;
}