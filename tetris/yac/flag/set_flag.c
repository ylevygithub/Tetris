/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** set the flagsv in a structure
*/

#include "../../include/my.h"

flag_t *set_flag_struct(char **av)
{
    flag_t *flag = malloc(sizeof(flag_t));
    flag->col = map_size_col(av);
    flag->row = map_size_row(av);
    flag->drop = flag_drop(av);
    flag->left = flag_left(av);
    flag->level = flag_level(av);
    flag->pause = pause_restart(av);
    flag->quit = flag_quit(av);
    flag->right = flag_right(av);
    flag->top = flag_top(av);
    return (flag);
}