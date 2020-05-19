/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** clean the game
*/

#include "../include/my.h"

void down_all_line(game_info_t *game, char **copy, int y)
{
    int it = 2;
    int x = 1;

    while (game->map[1][x] != '|') {
        game->map[1][x] = ' ';
        x++;
    }
    while (it <= y) {
        game->map[it] = my_strcpy(copy[it - 1]);
        it++;
    }
}

int line_full(char *str)
{
    int x = 1;

    while (str[x] != '|') {
        if (str[x] != '*')
            return (0);
        x++;
    }
    return (1);
}

int clean_line(game_info_t *game)
{
    char **copy = my_tabcpy(game->map);
    int y = 1;

    while (game->map[y]) {
        if (line_full(game->map[y]) == 1) {
            down_all_line(game, copy, y);
            return (0);
        }
        y++;
    }
    return (0);
}
