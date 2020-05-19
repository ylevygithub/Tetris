#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ncurses.h>
#include <curses.h>

struct player_s
{
    WINDOW *curwin;
    int y_loc;
    int x_loc;
    int x_max;
    int y_max;
    char character;
    int choice;
};
typedef struct player_s player_t;