/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** get flags
*/

#include "my_ls.h"

static options_t *initialize_flags(void)
{
    options_t *options = malloc(sizeof(options_t));

    if (options == NULL)
        exit(EXIT_ERROR);
    options->l = false;
    options->R = false;
    options->d = false;
    options->r = false;
    options->t = false;
    options->a = false;
    return options;
}

static void check_is_flag(char flag)
{
    int i = 0;
    char *opt_list = "lRdrta";

    for (; opt_list[i] != flag && opt_list[i] != '\0'; i++);
    if (opt_list[i] == '\0')
        exit(EXIT_ERROR);
}

static void toggle_flag(options_t *options, char flag)
{
    if (flag == 'l')
        options->l = true;
    if (flag == 'R')
        options->R = true;
    if (flag == 'd')
        options->d = true;
    if (flag == 'r')
        options->r = true;
    if (flag == 't')
        options->t = true;
    if (flag == 'a')
        options->a = true;
}

options_t *get_flags(int argc, char **argv)
{
    int i = 1;
    options_t *options = initialize_flags();

    if (argc <= 1)
        return options;
    for (; i < argc && argv[i][0] == '-'; i++)
        for (int k = 1; argv[i][k] != '\0'; k++) {
            check_is_flag(argv[i][k]);
            toggle_flag(options, argv[i][k]);
        }
    return options;
}