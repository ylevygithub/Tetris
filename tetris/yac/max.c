/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** max col and max line
*/

#include "../include/my.h"

int col_max(char **tab)
{
    int it = 1;
    int x = 0;
    int save = 0;

    while (tab[it]) {
        while (tab[it][x]) {
            x++;
        }
        x--;
        if (x > save)
            save = x;
        x = 0;
        it++;
    }
    return (save);
}

int line_max(char **tab)
{
    int it = 0;

    while (tab[it])
        it++;
    it--;
    return (it);
}
