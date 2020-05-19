/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** find the level
*/

#include "../../include/my.h"

int find_level2(char **av, int i, int j)
{
    while (av[i][j] != 0) {
        if (av[i][j] == '-' && av[i][j+1] == 'L')
            return (i);
        else if (av[i][j] == 'v' && av[i][j+1] == 'e')
            return (i);
        else
            j++;
    }
    return (50);
}

int find_level(char **av)
{
    int i = 1;
    int j = 0;

    while (av[i] != NULL) {
        if (find_level2(av, i, j) != 50)
            return (i);
        else {
            j = 0;
            i++;
        }
    }
    return (50);
}

int flag_level(char **av)
{
    int level;
    int i = find_level(av);

    if (av[i][0] == '-' && av[i][1] == 'L')
        level = my_getnbr(av[i + 1]);
    else if (av[i][0] == '-' &&
    av[i][1] == '-' && av[i][2] == 'l' && av[i][3] == 'e' &&
    av[i][4] == 'v' && av[i][5] == 'e' && av[i][6] == 'l' &&
    av[i][7] == '=')
        level = my_getnbr(my_charcpy(av[i][8]));
    else
        level = 1;
    return (level);
}
