/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** find the flag drop
*/

#include "../../include/my.h"

int find_drop2(char **av, int i, int j)
{
    while (av[i][j] != 0) {
        if (av[i][j] == '-' && av[i][j+1] == 'd')
            return (i);
        else if (av[i][j] == 'r' && av[i][j+1] == 'o')
            return (i);
        else
            j++;
    }
    return (50);
}

int find_drop(char **av)
{
    int i = 1;
    int j = 0;

    while (av[i] != NULL) {
        if (find_drop2(av, i, j) != 50)
            return (i);
        else {
            j = 0;
            i++;
        }
    }
    return (50);
}

char *flag_drop(char **av)
{
    int i = find_drop(av);

    if (av[i][0] == '-' && av[i][1] == 'd') {
        return (my_charcpy(av[i + 1][0]));
    }
    else if (av[i][0] == '-' &&
    av[i][1] == '-' && av[i][2] == 'k' && av[i][3] == 'e' &&
    av[i][4] == 'y' && av[i][5] == '-' && av[i][6] == 'd' &&
    av[i][7] == 'r' && av[i][8] == 'o' && av[i][9] == 'p' &&
    av[i][10] == '=') {
        return (my_charcpy(av[i][11]));
    }
    else
        return ((char*)"^EOB");
}
