/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** main.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        write(1, &str[i], 1);
        i++;
    }
}

char *get_name(char **av)
{
    int i = 0;
    int x = 0;
    char *path = av[1];
    char *tmp = malloc(sizeof(char) * strlen(av[1]) + 1);

    while (path[i] != '/')
        i++;
    i++;
    while (path[i] != '.') {
        tmp[x] = path[i];
        i++;
    }
    tmp[x+1] = '\0';
    return (tmp);
}

char *get_content(int fd, int size, char *buff, const char *pathname)
{
    if (fd = open(pathname, O_RDONLY)) {
        struct stat jack;
        stat(pathname, &jack);
        size = jack.st_size;
        buff = malloc(sizeof(char) * (size + 1));
        read(fd, buff, size);
        buff[size] = '\0';
        return (buff);
    }
    return (0);
}

char *get_buff(int fd, int size, char *buff, const char *pathname)
{
    int i = 0;
    int x = 0;
    char *buffer = get_content(fd, size, buff, pathname);
    char *tmp = malloc(sizeof(char) * strlen(buffer) + 1);
    while (buffer[i] != '\n')
        i++;
    i++;
    while (buffer[i] != '\0') {
        tmp[x] = buffer[i];
        i++;
        x++;
    }
    tmp[x] = '\0';
    return (tmp);
}
int main(int ac, char **av)
{
    const char *pathname = av[1];
    int size;
    int i = 0;
    int fd;
    char *buff = get_content(fd, size, buff, pathname);
    char *tmp = get_buff(fd, size, buff, pathname);
    char *name = get_name(av);

    my_putstr("Tetriminos :  Name ");
    my_putstr(name);
    my_putstr(" : Size ");
    my_putchar(buff[i]);
    my_putchar('*');
    my_putchar(buff[i+2]);
    my_putstr(" :  ");
    my_putstr("Color ");
    my_putchar(buff[i+4]);
    my_putstr(" :\n");
    my_putstr(tmp);
    free(tmp);
    free(buff);
    return (0);
}
