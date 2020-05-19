/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** check the tetriminos
*/

#include "../include/my.h"

int error_file(char **tab)
{
    int it = 0;

    while (tab[0][it]) {
        if (is_numorspace(tab[0][it]) == 1)
            return (84);
        it++;
    }
    if (tab[0][0] < (col_max(tab) + 48))
        return (84);
    if (tab[0][2] != (line_max(tab) + 48))
        return (84);
    return (0);
}

int tetri_cheak(struct dirent **directory)
{
    int i = 0;
    int save;

    while (directory[i] != NULL) {
        if (!(directory[i]->d_name[0] == '.')) {
            (check_tetrimino(complet(directory[i]->d_name)) != 84) ? save++ : 1;
        }
        i = i + 1;
    }
    my_putchar('\n');
    return (save);
}

int my_tetri_cheak(void)
{
    DIR* rep = NULL;
    struct dirent **directory = malloc(sizeof(struct dirent) *
        (my_count_dirent("tetriminos") + 1));

    rep = opendir("tetriminos");
    reg_cas(directory, rep);
    tetri_cheak(directory);
    return (0);
}

int check_tetrimino(char *path)
{
    char **tab;
    if ((tab = set_tab(path)) == NULL)
        return (84);

    if (error_file(tab) == 84) {
        return (84);
    }
    my_putstr("Tetriminos : Name ");
    my_put_name(path);
    my_putstr(" : Size ");
    my_putchar(tab[0][0]);
    my_putchar('*');
    my_putchar(tab[0][2]);
    my_putstr(" : Color ");
    my_putchar(tab[0][4]);
    my_putstr(" :\n");
    my_show_tetrimino(tab);
    return (0);
}

char *complet(char *str)
{
    int x = 11;
    int it = 0;
    char *rep = malloc(sizeof(char) * my_strlen(str) + 12);
    set_start_rep(rep);

    while (str[it]) {
        rep[x] = str[it];
        x++;
        it++;
    }
    rep[x] = '\0';
    return (rep);
}
