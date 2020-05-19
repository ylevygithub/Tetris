/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** creation of the map
*/

#include "../include/my.h"

void my_put_tetris_in_file(char **map, int fd, int i, int end_x)
{
    while (map[i] != NULL) {
        write(fd, map[i], end_x + 1);
        my_putstr_in_fd("\n", fd);
        i++;
    }
}

char **map_create_part(char **map, tetris_creation_t tetris, int i, int j)
{
    while (j <= tetris.end_x) {
        if ((i == 0 && j == 0 )|| (i == 0 && j == tetris.end_x)||
        (i == tetris.end_y && j == 0) ||
        (i == tetris.end_y && j == tetris.end_x))
            map[i][j] = '+';
        else if ((i == 0 && j != 0) || (i == 0 && j != tetris.end_x) ||
        (i == tetris.end_y && j != 0) ||
        (i == tetris.end_y && j != tetris.end_x))
            map[i][j] = '-';
        else if ((i != 0 && i != tetris.end_y && j == 0) || j == tetris.end_x)
            map[i][j] = '|';
        else
            map[i][j] = ' ';
        j++;
    }
    return (map);
}

char **map_create(char **map, tetris_creation_t tetris)
{
    int i = 0;
    int j = 0;

    while (i <= tetris.end_y) {
        map[i] = malloc(sizeof(char) * tetris.end_x + 1);
        map = map_create_part(map, tetris, i, j);
        j = 0;
        i++;
    }
    map[i] = NULL;
    return (map);
}

void all(char **av)
{
    char **map;
    flag_t *flag = set_flag_struct(av);
    tetris_creation_t tetris;

    tetris.end_x = flag->col * 2;
    tetris.end_y = flag->row;
    if (tetris.end_x <= 6 || tetris.end_y <= 4) {
        my_putstr_error("ERROR : Lines cannot be smaller than 5");
        my_putstr_error(" and columns cannot be smaller than 3.\n");
        return ;
    }
    map = malloc(sizeof(char *) * (tetris.end_y + 1));
    map = map_create(map, tetris);
    tetris_game(map);
}
