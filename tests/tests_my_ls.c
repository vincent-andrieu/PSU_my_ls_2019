/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** criterion tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "my_ls.h"

Test(my_ls, test_basic_ls)
{
    char **argv = malloc(sizeof(char) * 2);

    if (argv != NULL) {
        argv[0] = my_strdup("./my_ls");
        argv[1] = NULL;
        cr_assert_eq(my_ls(1, argv), EXIT_SUCCESS);
    }
}

Test(my_ls, test_basic_ls_flag_r)
{
    char **argv = malloc(sizeof(char) * 2);

    if (argv != NULL) {
        argv[0] = my_strdup("./my_ls");
        argv[1] = my_strdup("-r");
        cr_assert_eq(my_ls(2, argv), EXIT_SUCCESS);
    }
}

Test(my_ls, test_not_flag)
{
    char **argv = malloc(sizeof(char) * 2);

    if (argv != NULL) {
        argv[0] = my_strdup("./my_ls");
        argv[1] = my_strdup("-w");
        cr_assert_eq(my_ls(2, argv), EXIT_ERROR);
    }
}

Test(my_ls, test_ls_flag_d)
{
    char **argv = malloc(sizeof(char) * 4);

    if (argv != NULL) {
        argv[0] = my_strdup("./my_ls");
        argv[1] = my_strdup("-dl");
        argv[2] = my_strdup("include/");
        argv[3] = my_strdup("src/");
        cr_assert_eq(my_ls(2, argv), EXIT_SUCCESS);
    }
}

Test(my_ls, test_ls_flag_d_r)
{
    char **argv = malloc(sizeof(char) * 4);

    if (argv != NULL) {
        argv[0] = my_strdup("./my_ls");
        argv[1] = my_strdup("-dlr");
        argv[2] = my_strdup("include/");
        argv[3] = my_strdup("src/");
        cr_assert_eq(my_ls(4, argv), EXIT_SUCCESS);
    }
}

Test(my_ls, test_ls_flag_l_a_multifiles)
{
    char **argv = malloc(sizeof(char) * 4);

    if (argv != NULL) {
        argv[0] = my_strdup("./my_ls");
        argv[1] = my_strdup("-la");
        argv[2] = my_strdup("include/");
        argv[3] = my_strdup("src/");
        cr_assert_eq(my_ls(4, argv), EXIT_SUCCESS);
    }
}

Test(my_ls, test_ls_flag_l_r_multifiles)
{
    char **argv = malloc(sizeof(char) * 4);

    if (argv != NULL) {
        argv[0] = my_strdup("./my_ls");
        argv[1] = my_strdup("-lr");
        argv[2] = my_strdup("include/");
        argv[3] = my_strdup("src/");
        cr_assert_eq(my_ls(4, argv), EXIT_SUCCESS);
    }
}

Test(my_ls, test_ls_flag_l_ur_r_t)
{
    char **argv = malloc(sizeof(char) * 5);

    if (argv != NULL) {
        argv[0] = my_strdup("./my_ls");
        argv[1] = my_strdup("-l");
        argv[2] = my_strdup("-R");
        argv[3] = my_strdup("-r");
        argv[4] = my_strdup("-t");
        cr_assert_eq(my_ls(5, argv), EXIT_SUCCESS);
    }
}

Test(my_ls, test_ls_flag_l_dev_folders)
{
    char **argv = malloc(sizeof(char) * 4);

    if (argv != NULL) {
        argv[0] = my_strdup("./my_ls");
        argv[1] = my_strdup("-lR");
        argv[2] = my_strdup("/dev/v4l");
        argv[3] = my_strdup("/dev/vcs");
        cr_assert_eq(my_ls(4, argv), EXIT_SUCCESS);
    }
}