/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** check
*/

#include "../include/my.h"

int check_null(tetris_t *tetris)
{
    if (tetris->buff == NULL)
        return (84);
    if (tetris->new_buff == NULL)
        return (84);
    if (tetris->name == NULL)
        return (84);
    return (0);
}

int check_av(char **av)
{
    if (flag_debug(av) == 0) {
        all(av);
        exit(0);
        return (2);
    }
    return (-1);
}

int check_arg(int ac, char **av)
{
    if (ac == 1)
        all(av);
    else if ((av[1][0] == '-' && av[1][1] == 'h') || (av[1][0] == '-' &&
    av[1][1] == '-' && av[1][2] == 'h' && av[1][3] == 'e' &&
    av[1][4] == 'l' && av[1][5] == 'p')) {
        print_usage();
    }
    else if (ac > 1) {
        if (check_av(av) == -1) {
            all(av);
            return (0);
        }
        else if (check_av(av) == 2)
            return (0);
    }
    return (0);
}
