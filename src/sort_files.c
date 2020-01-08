/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** sort files
*/

#include "my_ls.h"

file_t *swap_files(file_t *files, file_t *last)
{
    struct file_s *temp;

    if (last != NULL)
        last->next = files->next;
    last = files->next;
    temp = files->next->next;
    files->next->next = files;
    files->next = temp;
    files = last;
    return files;
}

file_t *my_rev_list(file_t *first, file_t *files, file_t *prev)
{
    if (files != NULL) {
        first = my_rev_list(first, files->next, files);
        files->next = prev;
    } else
        first = prev;
    return first;
}