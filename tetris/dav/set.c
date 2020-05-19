/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** set
*/

#include "../include/my.h"

game_info_t *set_struct_game(char **map, int x)
{
    game_info_t *game = malloc(sizeof(game_info_t));

    game->map = map;
    game->score = 0;
    game->lvl = 0;
    game->total = x;
    game->in = 0;
    return (game);
}

void set_tetri_on_map(tetris_in_t *in, game_info_t *game)
{
    int col = in->column;
    int line = in->line;
    int it = 0;
    int b = 0;
    int y = 0;

    for (int x = 0; x < in->y; x++) {
        while (y < in->x && in->fig[it][b]) {
            game->map[line][col] = in->fig[it][b];
            b++;
            col++;
            y++;
        }
        line++;
        it++;
        b = 0;
        col = in->column;
        y = 0;
    }
}

void set_terminal_info(t_terminal_size *terminal, char **map)
{
    terminal->y = (terminal->y / 2) - (column_size_tab(map) / 2);
    terminal->x = (terminal->x / 2) - (line_size_tab(map) / 2);
    terminal->save_x = terminal->x;
    terminal->save_y = terminal->y;
}

t_terminal_size *init_terminal(game_info_t *game)
{
    t_terminal_size *terminal = malloc(sizeof(t_terminal_size));

    set_terminal_info(terminal, game->map);
    initscr();
    keypad(stdscr, 1);
    getmaxyx(stdscr, terminal->y, terminal->x);
    return (terminal);
}
