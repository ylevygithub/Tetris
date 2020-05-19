/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** flag debug
*/

#include "../../include/my.h"

int find_debug2(char **av, int i, int j)
{
    while (av[i][j] != 0) {
        if (av[i][j] == '-' && av[i][j+1] == 'D')
            return (i);
        else if (av[i][j] == 'e' && av[i][j+1] == 'b')
            return (i);
        else
            j++;
    }
    return (50);
}

int find_debug(char **av)
{
    int i = 1;
    int j = 0;

    while (av[i] != NULL) {
        if (find_debug2(av, i, j) != 50)
            return (i);
        else {
            j = 0;
            i++;
        }
    }
    return (50);
}

int flag_debug(char **av)
{
    int i = find_debug(av);

    if (av[i][0] == '-' && av[i][1] == 'D') {
        debug_mode(av);
    }
    else if (av[i][0] == '-' &&
    av[i][1] == '-' && av[i][2] == 'd' && av[i][3] == 'e' &&
    av[i][4] == 'b' && av[i][5] == 'u' && av[i][6] == 'g') {
        debug_mode(av);
    }
    else
        return (1);
    return (0);
}
