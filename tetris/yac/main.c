/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** main.c
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    if (check_arg(ac, av) == -1)
        return (84);
    return (0);
}
