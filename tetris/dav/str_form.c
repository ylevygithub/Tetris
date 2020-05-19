/*
** EPITECH PROJECT, 2019
** str_form
** File description:
** str_form
*/

#include "../include/my.h"

int count_to_first(char *str)
{
    int it = 0;

    while (str[it] != '\n' && str[it]) {
        it++;
    }
    return (it);
}

int my_count(char *str)
{
    int a = 0;
    int b = 0;

    while (str[a] != '\0'){
        if (verif_char(str[a]) == 1 &&
            verif_char(str[a + 1]) != 1){
            b = b + 1;
        }
        a = a + 1;
    }
    return (b);
}

int my_col_size(char *str, int i)
{
    while (str[i] != '\0') {
        if (verif_char(str[i]) != 1)
            return (i);
        i++;
    }
    return (i);
}

int str_form_part(char *str, int a)
{
    while (str[a] && verif_char(str[a]) != 1)
        a = a + 1;
    return (a);
}

char **str_form(char *str)
{
    int y = my_count(str) - 1;
    char **argv = malloc(sizeof(char *) * (y + 1));
    int a = count_to_first(str);
    int c = 0;

    for (int b = 0; b < y; b++) {
        c = 0;
        a = str_form_part(str, a);
        argv[b] = malloc(sizeof(char) * my_col_size(str, a) + 2);
        while (str[a] != '\0' && verif_char(str[a]) != 0) {
            argv[b][c] = str[a];
            c = c + 1;
            a = a + 1;
        }
        argv[b][c] = '\0';
        a = a + 1;
    }
    argv[y] = NULL;
    return (argv);
}
