/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** sort files
*/

#include "my.h"
#include "my_ls.h"

static bool is_alpha_sorted(file_t *files)
{
    if (files == NULL)
        return true;
    for (int i = 0; i < my_strlen(files->name)
        && i < (files->next != NULL) ? my_strlen(files->next->name) : 0; i++)
        if (files->name[i] > files->next->name[i])
            return false;
    if (files->next == NULL)
        return true;
    return is_alpha_sorted(files->next);
}

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

file_t *sort_alpha_files(file_t *first, file_t *files, file_t *last)
{
    if (files == NULL)
        return sort_alpha_files(first, first, NULL);
    if (is_alpha_sorted(first))
        return first;
    for (int i = 0; files->next != NULL
    && i <= my_strlen(files->name) && i <= my_strlen(files->next->name)
    && files->name[i] >= files->next->name[i]; i++)
        if (files->name[i] > files->next->name[i]) {
            files = swap_files(files, last);
            first = last == NULL ? files : first;
            return sort_alpha_files(first, first, NULL);
        }
    return sort_alpha_files(first, files->next, files);
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