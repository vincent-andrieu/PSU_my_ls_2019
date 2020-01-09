/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** stock files in a chain list
*/

#include <dirent.h>
#include "my.h"
#include "my_ls.h"

static struct stat get_filepath_stats(char *path, char *name)
{
    struct stat st;
    char *filepath = get_filepath(path, name);
    int error;

    if (filepath == NULL)
        exit(EXIT_ERROR);
    error = lstat(filepath, &st);
    free(filepath);
    if (error == -1)
        exit(EXIT_ERROR);
    return st;
}

static file_t *fill_file(char *path, char *name, file_t *next,
                        bool get_allfiles)
{
    file_t *file;

    if (path != NULL && name != NULL && (name[0] != '.' || get_allfiles)) {
        file = malloc(sizeof(file_t));
        if (file == NULL)
            return NULL;
        file->name = my_strdup(name);
        file->st = get_filepath_stats(path, name);
        if (file->name == NULL)
            return NULL;
        file->next = next;
        return file;
    }
    return next;
}

char *get_filepath(char *path, char *name)
{
    char *filepath = my_strndup(path, my_strlen(path) + my_strlen(name) + 1);

    if (filepath == NULL)
        return NULL;
    my_strcat(filepath, "/");
    my_strcat(filepath, name);
    return filepath;
}

static file_t *check_one_file(char *path, bool get_allfiles)
{
    char *name = NULL;
    int i = my_strlen(path);
    file_t *file;

    for (; path != NULL && i >= 0 && path[i] != '/'; i--);
    name = path + i + 1;
    path[i] = '\0';
    file = fill_file(path, name, NULL, get_allfiles);
    path[i] = '/';
    free(file->name);
    file->name = my_strdup(path);
    return check_permissions(file);
}

file_t *get_files(char *path, options_t *options)
{
    DIR *dir = opendir(path);
    struct dirent *d_file = dir != NULL ? readdir(dir) : NULL;
    file_t *files = NULL;

    if (dir == NULL || d_file == NULL)
        return check_one_file(path, options->a);
    while (d_file != NULL) {
        files = fill_file(path, d_file->d_name, files, options->a);
        d_file = readdir(dir);
    }
    closedir(dir);
    if (files == NULL)
        return NULL;
    if (options->t)
        files = sort_time(files, files, NULL);
    if (options->r)
        files = my_rev_list(files, files, NULL);
    return files;
}