/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** recode ls
*/

#include <dirent.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include "my.h"
#include "my_ls.h"

static char *cat_file_to_path(char *path, char *name)
{
    char *filepath = my_strndup(path, my_strlen(path) + my_strlen(name) + 1);

    if (filepath == NULL)
        exit(EXIT_ERROR);
    my_strcat(filepath, "/");
    my_strcat(filepath, name);
    return filepath;
}

static char get_file_type(struct stat st)
{
    if (S_ISREG(st.st_mode))
        return 'f';
    if (S_ISDIR(st.st_mode))
        return 'd';
    if (S_ISLNK(st.st_mode))
        return 'l';
    if (S_ISFIFO(st.st_mode))
        return 'p';
    if (S_ISSOCK(st.st_mode))
        return 's';
    if (S_ISBLK(st.st_mode))
        return 'b';
    if (S_ISCHR(st.st_mode))
        return 'c';
    return 0;
}

static void list_files(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *d_file = dir != NULL ? readdir(dir) : NULL;
    struct stat st;
    char *filepath;

    if (dir == NULL || d_file == NULL)
        exit(EXIT_ERROR);
    while (d_file != NULL) {
        if (my_strcmp(d_file->d_name, ".") && my_strcmp(d_file->d_name, "..")) {
            filepath = cat_file_to_path(path, d_file->d_name);
            lstat(filepath, &st);
            printf("File name : %s\n", d_file->d_name);
            printf("File type : %c\n", get_file_type(st));
            printf("File lnode : %ld\n", st.st_ino);
            printf("Number of hard links : %ld\n", st.st_nlink);
            printf("File size : %ld\n", st.st_size);
            printf("Allocated space on hard drive : %ld\n", st.st_blocks * 512);
            printf("Minor : %d\n", minor(st.st_dev));
            printf("Major : %d\n", major(st.st_dev));
            printf("Owner's UID : %d\n", st.st_uid);
            printf("Owner's GID : %d\n", st.st_gid);
            printf("\n");
            free(filepath);
        }
        d_file = readdir(dir);
    }
    closedir(dir);
}

int main(int argc, char **argv)
{
    options_t *options = get_flags(argc, argv);

    list_files(argv[1]);
    return EXIT_SUCCESS;
}