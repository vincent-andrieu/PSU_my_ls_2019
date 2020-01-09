/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** put flag l details
*/

#include <time.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <pwd.h>
#include <grp.h>
#include "my.h"
#include "my_ls.h"

static char get_file_type(struct stat st)
{
    if (S_ISREG(st.st_mode))
        return '-';
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

static void put_file_permissions(struct stat st)
{
    my_putchar((st.st_mode & S_IRUSR) ? 'r' : '-');
    my_putchar((st.st_mode & S_IWUSR) ? 'w' : '-');
    my_putchar((st.st_mode & S_IXUSR) ? 'x' : '-');
    my_putchar((st.st_mode & S_IRGRP) ? 'r' : '-');
    my_putchar((st.st_mode & S_IWGRP) ? 'w' : '-');
    my_putchar((st.st_mode & S_IXGRP) ? 'x' : '-');
    my_putchar((st.st_mode & S_IROTH) ? 'r' : '-');
    my_putchar((st.st_mode & S_IWOTH) ? 'w' : '-');
    if ((st.st_mode & S_ISVTX) && !(st.st_mode & S_IXOTH))
        my_putchar('T');
    else if ((st.st_mode & S_ISVTX) && (st.st_mode & S_IXOTH))
        my_putchar('t');
    else
        my_putchar((st.st_mode & S_IXOTH) ? 'x' : '-');
    my_putstr(". ");
}

static void put_month(struct stat st)
{
    int i = 0;
    char *date;

    date = ctime(&st.st_mtime);
    for (; date[0] != ' ' && date[0] != '\0'; date++);
    if (date[0] == '\0')
        return;
    date++;
    for (; date[i] != ':' && date[i] != '\0'; i++);
    for (i++; date[i] != ':' && date[i] != '\0'; i++);
    date[i] = '\0';
    my_putstr(date);
    my_putchar(' ');
}

static void put_major(struct stat st)
{
    if (S_ISBLK(st.st_mode) || S_ISCHR(st.st_mode)) {
        my_put_nbr(major(st.st_rdev));
        my_putstr(", ");
    }
}

void put_details(file_t *files, int sp_nlinks, int sp_size)
{
    my_putchar(get_file_type(files->st));
    put_file_permissions(files->st);
    for (int i = 0; i < sp_nlinks - get_num_nbr(files->st.st_nlink); i++)
        my_putchar(' ');
    my_put_nbr(files->st.st_nlink);
    my_putchar(' ');
    my_putstr(getpwuid(files->st.st_uid)->pw_name);
    my_putchar(' ');
    my_putstr(getgrgid(files->st.st_gid)->gr_name);
    my_putchar(' ');
    put_major(files->st);
    for (int i = 0; i < sp_size - get_num_nbr(files->st.st_size); i++)
        my_putchar(' ');
    my_put_nbr(files->st.st_size);
    my_putchar(' ');
    put_month(files->st);
    my_putstr(files->name);
    my_putchar('\n');
}