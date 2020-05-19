/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** lib2 functions
*/

#include "../include/my.h"

char *my_charcpy(char c)
{
    char *res = malloc(sizeof(char) * 2);

    res[0] = c;
    res[1] = '\0';
    return (res);
}

void my_putstr_in_fd(char *str, int fd)
{
    int i = 0;

    while (str[i] != 0) {
        write(fd, &str[i], my_strlen(str));
        i++;
    }
}

int my_getnbr(char *str)
{
    int nbr = 0;
    int a = 0;
    int x = 0;

    if (str[a] == '-')
        a++;
    while (str[a] != '\0') {
        if (str[a] >= '0' && str[a] <= '9') {
            if (x != 0) {
                nbr = nbr * 10;
            }
            nbr = nbr + str[a] - 48;
            x = x + 1;
        }
        a = a + 1;
    }
    if (str[0] == '-'){
        nbr = nbr * -1;
    }
    return (nbr);
}

int my_putnbr(int nb)
{
    int i;

    if (nb < 0 && nb != -2147483648) {
        write(1, "-", 1);
        i = -nb;
        my_putnbr(i);
    }
    else if (nb == -2147483648)
        write(1, "-2147483648", 11);
    else {
        i = nb;
        if (i >= 10)
            my_putnbr(i / 10);
        my_putchar(i % 10 + '0');
    }
    return (0);
}

void my_put_name(char *str)
{
    int x = 11;

    while (str[x]) {
        my_putchar(str[x]);
        x++;
    }
}
