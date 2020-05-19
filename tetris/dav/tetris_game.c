/*
** EPITECH PROJECT, 2019
** set_tetri_on_map
** File description:
** set_tetri_map
*/

#include "../include/my.h"

int my_rand(int x)
{
    int n = 0;
    time_t t;

    srand((unsigned) time(&t));
    n = rand()% (x - 1);
    return (n);
}

int loose_condition(tetris_in_t *in, game_info_t *game)
{
    int y = 1;
    int save_x = in->x;
    int save_y = in->y;

    for (int b = 0; b < save_y; b++) {
        if (verif_line_loose(game->map[y], save_x) == 1)
            return (1);
        y++;
    }
    return (0);
}

float my_clock(clock_t start_t, game_info_t *game, t_terminal_size *terminal,
tetris_in_t **in)
{
    static float it = 0;
    if (((start_t / it) < 500000) == 0) {
        down_tetrimino(in[game->in], game, terminal);
        it++;
    }
    return (it);
}

void game_loop(tetris_in_t **in, game_info_t *game, t_terminal_size *terminal)
{
    clock_t start_t = clock();

    while (loose_condition(in[game->in], game) != 1) {
        game->in = my_rand(game->total);
        set_tetri_on_map(in[game->in], game);
        my_print_tab_window(terminal, game);
        while (verif_touch_down(in[game->in], game) != 1) {
            start_t = clock();
            my_clock(start_t, game, terminal, in);
            verif_action(in, game, terminal);
        }
        in[game->in]->line = 1;
        in[game->in]->column = 1;
        clean_line(game);
    }
}

int tetris_game(char **map)
{
    DIR* rep = NULL;
    struct dirent **directory = malloc(sizeof(struct dirent) *
        (my_count_dirent("tetriminos") + 1));
    tetris_in_t **in;
    game_info_t *game;
    t_terminal_size *terminal;

    rep = opendir("tetriminos");
    reg_cas(directory, rep);
    in = in_struct(directory);
    game = set_struct_game(map, count_valid(directory));
    terminal = init_terminal(game);

    game_loop(in, game, terminal);
    endwin();
    return (0);
}
