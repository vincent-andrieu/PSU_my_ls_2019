/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** check permission
*/

#include "my.h"
#include "my_ls.h"

file_t *check_permissions(file_t *file)
{
    if (S_ISDIR(file->st.st_mode)) {
        my_put_error_str("my_ls: cannot open directory '");
        my_put_error_str(file->name);
        my_put_error_str("': Permission denied\n");
        free_files(file);
        exit(EXIT_ERROR);
    }
    return file;
}