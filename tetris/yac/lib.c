/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** lib functions
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        write(1, &str[i], 1);
        i++;
    }
}

void my_putstr_error(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        write(2, &str[i], 1);
        i++;
    }
}

void my_putmap(char **map)
{
    int i = 0;

    while (map[i]) {
        write(1, map[i], my_strlen(map[i]));
        my_putchar('\n');
        i++;
    }
}

void my_putmap_in_fd(char **map, int fd)
{
    int i = 0;

    while (map[i]) {
        my_putstr_in_fd(map[i], fd);
        my_putchar('\n');
        i++;
    }
}
