/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** usage
*/

#include "../include/my.h"

void set_start_rep(char *rep)
{
    rep[0] = 't';
    rep[1] = 'e';
    rep[2] = 't';
    rep[3] = 'r';
    rep[4] = 'i';
    rep[5] = 'm';
    rep[6] = 'i';
    rep[7] = 'n';
    rep[8] = 'o';
    rep[9] = 's';
    rep[10] = '/';
}

void print_usage(void)
{
    my_putstr("Usage:   ./tetris [option]\nOptions:\n");
    my_putstr(" --help               Display this help\n");
    my_putstr(" -L --level={num}     Start Tetris at level num (def: 1)\n");
    my_putstr(" -l --key-left={K}    Move the tetrimino LEFT using the K ");
    my_putstr("key (def: left arrow)\n -r --key-right={K}   ");
    my_putstr("Move the tetrimino RIGHT using the K key (def: right arrow)\n");
    my_putstr(" -t --key-turn={K}    TURN the tetrimino clockwise ");
    my_putstr("90d using the K key (def: top arrow)\n -d --key-drop={K}    ");
    my_putstr("DROP the tetrimino using the K key (def: down arrow)\n");
    my_putstr(" -q --key-quit={K}    QUIT the game using the K key ");
    my_putstr("(def: ‘q’ key)\n -p --key-pause={K}   ");
    my_putstr("PAUSE/RESTART the game");
    my_putstr(" using the K key (def: space bar)\n");
    my_putstr(" --map-size={row,col} Set ");
    my_putstr("the numbers of rows and columns of the map (def: 20,10)\n");
    my_putstr(" -w --without-next    Hide next tetrimino (def: false)\n");
    my_putstr(" -D --debug           Debug mode (def: false)\n");
}
