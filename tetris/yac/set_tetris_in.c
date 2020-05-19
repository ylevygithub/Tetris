/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** set_struct_in
*/

#include "../include/my.h"

tetris_t *init_tetris(void)
{
    tetris_t *tetris;

    tetris = malloc(sizeof(tetris_t));
    if (tetris == NULL)
        return (NULL);
    return (tetris);
}

tetris_in_t *set_in_struct(char const *pathname)
{
    tetris_in_t *in = malloc(sizeof(tetris_in_t));
    char *form_str = my_open_read(pathname);

    in->x = my_getnbr(my_charcpy(form_str[0]));
    in->y = my_getnbr(my_charcpy(form_str[2]));
    in->column = 1;
    in->line = 1;
    in->fig = malloc(sizeof(figure_t));
    in->fig = str_form(form_str);
    return (in);
}

int error(char *path)
{
    char **tab;
    if ((tab = set_tab(path)) == NULL)
        return (84);

    if (error_file(tab) == 84) {
        return (84);
    }
    return (0);
}

int count_valid(struct dirent **directory)
{
    int save = 0;
    int i = 0;

    while (directory[i] != NULL) {
        if (!(directory[i]->d_name[0] == '.')) {
            (error(complet(directory[i]->d_name)) != 84) ?
            save++ : 1;
        }
        i = i + 1;
    }
    return (save);
}

tetris_in_t **in_struct(struct dirent **directory)
{
    tetris_in_t **in = malloc(sizeof(tetris_in_t *) * count_valid(directory));
    int i = 0;
    int x = 0;

    while (directory[i] != NULL) {
        if (!(directory[i]->d_name[0] == '.')) {
            if (error(complet(directory[i]->d_name)) != 84) {
                in[x] = set_in_struct(complet(directory[i]->d_name));
            }
            x++;
        }
        i = i + 1;
    }
    return (in);
}
