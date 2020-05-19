/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** find the flag right
*/

#include "../../include/my.h"

int find_right2(char **av, int i, int j)
{
    while (av[i][j] != 0) {
        if (av[i][j] == '-' && av[i][j+1] == 'r')
            return (i);
        else if (av[i][j] == 'g' && av[i][j+1] == 'h')
            return (i);
        else
            j++;
    }
    return (50);
}

int find_right(char **av)
{
    int i = 1;
    int j = 0;

    while (av[i] != NULL) {
        if (find_right2(av, i, j) != 50)
            return (i);
        else {
            j = 0;
            i++;
        }
    }
    return (50);
}

char *flag_right(char **av)
{
    int i = find_right(av);

    if (av[i][0] == '-' && av[i][1] == 'r') {
        return (my_charcpy(av[i + 1][0]));
    }
    else if (av[i][0] == '-' &&
    av[i][1] == '-' && av[i][2] == 'k' && av[i][3] == 'e' &&
    av[i][4] == 'y' && av[i][5] == '-' && av[i][6] == 'r' &&
    av[i][7] == 'i' && av[i][8] == 'g' && av[i][9] == 'h' &&
    av[i][10] == 't' && av[i][11] == '=') {
        return (my_charcpy(av[i][12]));
    }
    else
        return ((char*)"^EOC");
}
