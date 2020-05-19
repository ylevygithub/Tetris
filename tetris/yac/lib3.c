/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetriminos
*/

#include "../include/my.h"

void my_show_tetrimino(char **map)
{
    int it = 1;

    while (map[it]) {
        my_putstr(map[it]);
        my_putchar('\n');
        it++;
    }
}

char **set_tab(char *path)
{
    int fd = 0;
    struct stat byte;
    char *str_tab;
    char **tab;

    if ((fd = open(path, O_RDONLY)) == -1)
        return (NULL);
    stat(path, &byte);
    str_tab = malloc(sizeof(char) * byte.st_size);
    read(fd, str_tab, byte.st_size);
    tab = my_str_to_word_array(str_tab);
    return (tab);
}

int is_numorspace(char c)
{
    if (c == ' ')
        return (0);
    if (c < '0' && c > '9')
        return (1);
    return (0);
}
