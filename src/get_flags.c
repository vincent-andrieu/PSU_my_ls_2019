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
        return NULL;
    options->i = false;
    options->ur = false;
    options->d = false;
    options->r = false;
    options->t = false;
    options->a = false;
    return options;
}

static bool check_is_flag(char flag)
{
    int i = 0;
    char *opt_list = "lRdrta";

    for (; opt_list[i] != flag && opt_list[i] != '\0'; i++);
    if (opt_list[i] == '\0')
        return false;
    return true;
}

static void toggle_flag(options_t *options, char flag)
{
    if (flag == 'l')
        options->i = true;
    if (flag == 'R')
        options->ur = true;
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
    int error = EXIT_SUCCESS;

    if (options == NULL)
        return NULL;
    if (argc <= 1)
        return options;
    for (; i < argc && argv[i][0] == '-'; i++) {
        for (int k = 1; argv[i][k] != '\0'; k++) {
            error = check_is_flag(argv[i][k]);
            toggle_flag(options, argv[i][k]);
        }
        if (error == false)
            return NULL;
    }
    return options;
}