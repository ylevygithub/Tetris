/*
** EPITECH PROJECT, 2019
** set_map
** File description:
** set_map
*/

#include "../include/my.h"

int verif_char(char c)
{
    if (c == '\n') {
        return (0);
    }
    return (1);
}

int mon_compteur(char *str)
{
    int a = 0;
    int b = 0;

    while (str[a] != '\0'){
        if (verif_char(str[a]) == 1 &&
            verif_char(str[a + 1]) != 1) {
            b = b + 1;
        }
        a = a + 1;
    }
    return (b);
}

int my_wordlen(char *str, int i)
{
    while (str[i] != '\0') {
        if (verif_char(str[i]) != 1)
            return (i);
        i++;
    }
    return (i);
}

char **my_str_to_word_array(char *str)
{
    int y = mon_compteur(str) + 1;
    char **argv = malloc(sizeof(char *) * (y + 1));
    int a = 0;
    int c = 0;

    for (int b = 0; b < y; b++) {
        c = 0;
        while  (str[a] && verif_char(str[a]) != 1)
            a = a + 1;
        argv[b] = malloc(sizeof(char) * my_wordlen(str, a) + 2);
        while (str[a] != '\0' && verif_char(str[a]) != 0) {
            argv[b][c] = str[a];
            c = c + 1;
            a = a + 1;
        }
        argv[b][c] = '\0';
        a = a + 1;
    }
    argv[y - 1] = NULL;
    return (argv);
}
