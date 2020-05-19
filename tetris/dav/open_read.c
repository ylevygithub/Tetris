/*
** EPITECH PROJECT, 2019
** open_read
** File description:
** open_read
*/

#include "../include/my.h"

char *my_open_read(const char *path)
{
    char str_tab[30000];
    int x = 0;
    int it = 0;
    char *res;
    int fd = open(path, O_RDONLY);

    read(fd, str_tab, 30000);
    it = my_strlen(str_tab);
    res = malloc(sizeof(char) * it + 1);
    while (x < it) {
        res[x] = str_tab[x];
        x++;
    }
    res[x] = '\0';
    return (res);
}

char **tab_form(const char *pathname)
{
    char *form_str = my_open_read(pathname);
    char **form = str_form(form_str);

    return (form);
}

char **game_map1(const char *pathname)
{
    char *str = my_open_read(pathname);
    char **map = my_str_to_word_array(str);

    return (map);
}
