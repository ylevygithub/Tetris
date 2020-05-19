/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** verifications
*/

#include "../include/my.h"

int verif_touch_down(tetris_in_t *in, game_info_t *game)
{
    int it = 0;
    int x = in->column;
    int y = in->line;
    int size_x = in->x;
    int size_y = in->y;
    y = y + size_y;

    while (it < size_x) {
        if (game->map[y][x] != ' ')
            return (1);
        x++;
        it++;
    }
    return (0);
}

int verif_touch_right(tetris_in_t *in, game_info_t *game)
{
    int it = 0;
    int x = in->column + in->x;
    int y = in->line;
    int size = in->y;

    while (it < size) {
        if (game->map[y][x] != ' ')
            return (1);
        y++;
        it++;
    }
    return (0);
}

int verif_touch_left(tetris_in_t *in, game_info_t *game)
{
    int it = 0;
    int x = in->column - 1;
    int y = in->line;
    int size = in->y;

    while (it < size) {
        if (game->map[y][x] != ' ')
            return (1);
        y++;
        it++;
    }
    return (0);
}

void verif_action(tetris_in_t **in, game_info_t *game,
t_terminal_size *terminal)
{
    int ch;
    noecho();
    nodelay(stdscr, true);
    ch = getch();
    (ch == KEY_DOWN) ? down_tetrimino(in[game->in], game, terminal) : 1;
    (ch == KEY_RIGHT) ? right_tetrimino(in[game->in], game, terminal) : 1;
    (ch == KEY_LEFT) ? left_tetrimino(in[game->in], game, terminal) : 1;
}

int verif_line_loose(char *str, int size)
{
    int it = 0;
    int x = 1;

    while (it < size) {
        if (str[x] != ' ') {
            return (1);
        }
        x++;
        it++;
    }
    return (0);
}
