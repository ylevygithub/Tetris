/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** manipulation of the tetriminos
*/

#include "../include/my.h"

void delet_form_in(tetris_in_t *in, game_info_t *game)
{
    int it = 0;
    int b = 0;
    int x = in->column;
    int y = in->line;

    while (it < in->y) {
        while (b < in->x) {
            game->map[y][x] = ' ';
            x++;
            b++;
        }
        x = in->column;
        b = 0;
        it++;
        y++;
    }
}

int down_tetrimino(tetris_in_t *in, game_info_t *game,
    t_terminal_size *terminal)
{
    int res;

    res = verif_touch_down(in, game);
    delet_form_in(in, game);
    in->line = in->line + 1;
    set_tetri_on_map(in, game);
    clear();
    my_print_tab_window(terminal, game);
    refresh();
    return (res);
}

int right_tetrimino(tetris_in_t *in, game_info_t *game,
t_terminal_size *terminal)
{
    if (verif_touch_right(in, game) == 1)
        return (1);
    delet_form_in(in, game);
    in->column = in->column + 1;
    set_tetri_on_map(in, game);
    clear();
    my_print_tab_window(terminal, game);
    refresh();
    return (0);
}

int left_tetrimino(tetris_in_t *in, game_info_t *game,
t_terminal_size *terminal)
{
    if (verif_touch_left(in, game) == 1)
        return (1);
    delet_form_in(in, game);
    in->column = in->column - 1;
    set_tetri_on_map(in, game);
    clear();
    my_print_tab_window(terminal, game);
    refresh();
    return (0);
}
