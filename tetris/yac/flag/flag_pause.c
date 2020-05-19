/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** find the flag pause/restart
*/

#include "../../include/my.h"

int find_pause2(char **av, int i, int j)
{
    while (av[i][j] != 0) {
        if (av[i][j] == '-' && av[i][j+1] == 'p')
            return (i);
        else if (av[i][j] == 'p' && av[i][j+1] == 'a')
            return (i);
        else
            j++;
    }
    return (50);
}

int find_pause(char **av)
{
    int i = 1;
    int j = 0;

    while (av[i] != NULL) {
        if (find_pause2(av, i, j) != 50)
            return (i);
        else {
            j = 0;
            i++;
        }
    }
    return (50);
}

char *pause_restart(char **av)
{
    int i = find_pause(av);

    if (av[i][0] == '-' && av[i][1] == 'p') {
        return (my_charcpy(av[i + 1][0]));
    }
    else if (av[i][0] == '-' &&
    av[i][1] == '-' && av[i][2] == 'k' && av[i][3] == 'e' &&
    av[i][4] == 'y' && av[i][5] == '-' && av[i][6] == 'p' &&
    av[i][7] == 'a' && av[i][8] == 'u' && av[i][9] == 's' &&
    av[i][10] == 'e' && av[i][11] == '=') {
        return (my_charcpy(av[i][12]));
    }
    else
        return ((char*)"(space)");
}
