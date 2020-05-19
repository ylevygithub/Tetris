/*
** EPITECH PROJECT, 2019
** lib_print
** File description:
** lib_print
*/

#include "../include/my.h"

char *my_strcpy(char *str)
{
    int it = 0;
    char *cpy = malloc(sizeof(char) * my_strlen(str) + 1);

    while (str[it]) {
        cpy[it] = str[it];
        it++;
    }
    cpy[it] = '\0';
    return (cpy);
}

int my_strlen(char *str)
{
    int it = 0;

    while (str[it])
        it++;
    return (it);
}

char **my_tabcpy(char **tab)
{
    char **map = malloc(sizeof(char * ) * (line_size_tab(tab) + 1));
    int y = 0;

    while (tab[y]) {
        map[y] = my_strcpy(tab[y]);
        y++;
    }
    map[y] = NULL;
    return (map);
}

void print_tab(char **map, int line_size, t_terminal_size *terminal)
{
    int x = 0;

    while (x < line_size) {
        mvprintw(terminal->y, terminal->x, map[x]);
        terminal->y = terminal->y + 1;
        x++;
    }
    terminal->y = terminal->save_y;
}

void my_print_tab_window(t_terminal_size *terminal, game_info_t *game)
{
    clear();
    getmaxyx(stdscr, terminal->y, terminal->x);
    if (terminal->y - 5 < line_size_tab(game->map) ||
    terminal->x - 5 < column_size_tab(game->map)) {
        clear();
        mvprintw(terminal->y/2, terminal->x/2, "too small window!");
        refresh();
    }
    else {
        set_terminal_info(terminal, game->map);
        print_tab(game->map, line_size_tab(game->map), terminal);
        refresh();
    }
}
