/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** find the size of the map
*/

#include "../../include/my.h"

int find_size2(char **av, int i, int j)
{
    while (av[i][j] != '\0') {
        if (av[i][j] == 's' && av[i][j+1] == 'i')
            return (i);
        else
            j++;
    }
    return (50);
}

int find_size(char **av)
{
    int i = 1;
    int j = 0;

    while (av[i] != NULL) {
        if (find_size2(av, i, j) != 50)
            return (i);
        else {
            j = 0;
            i++;
        }
    }
    return (50);
}

int map_size_row(char **av)
{
    int i = find_size(av);
    int row;

    if (av[i][0] == '-' &&
    av[i][1] == '-' && av[i][2] == 'm' && av[i][3] == 'a' &&
    av[i][4] == 'p' && av[i][5] == '-' && av[i][6] == 's' &&
    av[i][7] == 'i' && av[i][8] == 'z' && av[i][9] == 'e' &&
    av[i][10] == '=')
        row = my_getnbr(number_str(av[i], i));
    else
        row = 20;
    return (row);
}

int map_size_col(char **av)
{
    int i = find_size(av);
    int col;

    if (av[i][0] == '-' &&
    av[i][1] == '-' && av[i][2] == 'm' && av[i][3] == 'a' &&
    av[i][4] == 'p' && av[i][5] == '-' && av[i][6] == 's' &&
    av[i][7] == 'i' && av[i][8] == 'z' && av[i][9] == 'e' &&
    av[i][10] == '=')
        col = my_getnbr(number_str2(av[i], i));
    else
        col = 10;
    return (col);
}
