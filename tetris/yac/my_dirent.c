/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** my dirent
*/

#include "../include/my.h"

int reg_cas(struct dirent **directory, DIR *rep)
{
    int i = 0;
    struct dirent *rfile;

    while ((rfile = readdir(rep)) != NULL) {
        directory[i] = rfile;
        i = i + 1;
    }
    directory[i] = NULL;
    return (0);
}

int my_count_dirent(char *str)
{
    int i = 0;
    DIR *rep = NULL;
    struct dirent *rfile;

    rep = opendir(str);
    if (rep == NULL)
        return (0);
    while ((rfile = readdir(rep)) != NULL) {
        i = i + 1;
    }
    return (i);
}
