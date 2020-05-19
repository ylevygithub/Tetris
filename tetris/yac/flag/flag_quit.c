/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** find the flag quit
*/

#include "../../include/my.h"

int find_quit2(char **av, int i, int j)
{
    while (av[i][j] != 0) {
        if (av[i][j] == '-' && av[i][j+1] == 'q')
            return (i);
        else if (av[i][j] == 'q' && av[i][j+1] == 'u')
            return (i);
        else
            j++;
    }
    return (50);
}

int find_quit(char **av)
{
    int i = 1;
    int j = 0;

    while (av[i] != NULL) {
        if (find_quit2(av, i, j) != 50)
            return (i);
        else {
            j = 0;
            i++;
        }
    }
    return (50);
}

char *flag_quit(char **av)
{
    int i = find_quit(av);

    if (av[i][0] == '-' && av[i][1] == 'q') {
        return (my_charcpy(av[i + 1][0]));
    }
    else if (av[i][0] == '-' &&
    av[i][1] == '-' && av[i][2] == 'k' && av[i][3] == 'e' &&
    av[i][4] == 'y' && av[i][5] == '-' && av[i][6] == 'q' &&
    av[i][7] == 'u' && av[i][8] == 'i' && av[i][9] == 't' &&
    av[i][10] == '=') {
        return (my_charcpy(av[i][11]));
    }
    else
        return ((char*)"q");
}
