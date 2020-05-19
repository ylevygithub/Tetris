/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** size
*/

#include "../include/my.h"

int line_size_tab(char **tab)
{
    int it = 0;

    while (tab[it])
        it++;
    return (it);
}

int column_size_tab(char **tab)
{
    int it = 0;

    while (tab[0][it])
        it++;
    return (it);
}
