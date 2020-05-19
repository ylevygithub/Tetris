/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** debug
*/

#include "../include/my.h"

int debug_mode_part(flag_t *flag)
{
    char str_tab[3];

    my_putstr("\nSize  : ");
    my_putnbr(flag->row);
    my_putchar('*');
    my_putnbr(flag->col);
    my_tetri_cheak();
    my_putstr("Press any key to start Tetris\n");
    while (read(0, str_tab, 1) != 1);
    return (0);
}

void debug_mode(char **av)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));
    flag_t *flag = set_flag_struct(av);
    tetris->str = malloc(sizeof(char) * 3);

    my_putstr("*** DEBUG MODE ***\nKey Left  : ");
    my_putstr(flag->left);
    my_putstr("\nKey Right  : ");
    my_putstr(flag->right);
    my_putstr("\nKey Turn  : ");
    my_putstr(flag->top);
    my_putstr("\nKey Drop  : ");
    my_putstr(flag->drop);
    my_putstr("\nKey Quit  : ");
    my_putstr(flag->quit);
    my_putstr("\nKey Pause  : ");
    my_putstr(flag->pause);
    my_putstr("\nNext  : Yes\nLevel  : ");
    my_putnbr(flag->level);
    debug_mode_part(flag);
}
