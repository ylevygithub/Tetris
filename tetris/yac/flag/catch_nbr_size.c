/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** catch the number of row and col from str
*/

#include "../../include/my.h"

char *number_str(char *str, int i)
{
    i = 0;
    int j = 0;
    char *tmp = malloc(sizeof(char) * 5);

    while (str[i] != '=' && str[i])
        i++;
    i++;
    while (str[i] != ',' && str[i]) {
        tmp[j] = str[i];
        i++;
        j++;
    }
    tmp[j] = '\0';
    return (tmp);
}

char *number_str2(char *str, int i)
{
    i = 0;
    int j = 0;
    char *tmp = malloc(sizeof(char) * 3);

    while (str[i] != ',')
        i++;
    i++;
    while (str[i] != '\0') {
        tmp[j] = str[i];
        i++;
        j++;
    }
    tmp[j] = '\0';
    return (tmp);
}
