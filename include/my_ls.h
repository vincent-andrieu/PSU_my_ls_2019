/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** header
*/

#include <stdlib.h>
#include <stdbool.h>

#ifndef MY_RADAR_H_
#define MY_RADAR_H_

#define EXIT_ERROR 84

typedef struct options_s
{
    bool l;
    bool R;
    bool d;
    bool r;
    bool t;
} options_t;

options_t *get_flags(int argc, char **argv);

#endif