#include "my.h"

player_t *player_movement(WINDOW *win, int y, int x, char c)
{
    player_t *player;
    player->curwin = win;
    player->y_loc = y;
    player->x_loc = x;
    getmaxyx(win, player->y_max, player->x_max);
    keypad(win, true);
    c = '&';
    player->character = c;
    return (player);
}
void move_up()
{
    player_t *player = player_movement(player->curwin, player->y_loc, player->x_loc, player->character);
    mvwaddch(player->curwin, player->y_loc, player->x_loc, ' ');
    player->y_loc--;
    if (player->y_loc < 1)
        player->y_loc = 1;
}
void move_down()
{
    player_t *player = player_movement(player->curwin, player->y_loc, player->x_loc, player->character);
    mvwaddch(player->curwin, player->y_loc, player->x_loc, ' ');
    player->y_loc++;
    if (player->y_loc > player->y_max - 2)
        player->y_loc = player->y_max - 2;
}
void move_left()
{
    player_t *player = player_movement(player->curwin, player->y_loc, player->x_loc, player->character);
    mvwaddch(player->curwin, player->y_loc, player->x_loc, ' ');
    player->x_loc--;
    if (player->x_loc > 1)
        player->x_loc = 1;
}
void move_right()
{
    player_t *player = player_movement(player->curwin, player->y_loc, player->x_loc, player->character);
    mvwaddch(player->curwin, player->y_loc, player->x_loc, ' ');
    player->x_loc++;
    if (player->x_loc > player->x_max - 2)
        player->x_loc = player->x_max - 2;
}
int get_mv()
{
    player_t *player = player_movement(player->curwin, player->y_loc, player->x_loc, player->character);
    int choice = wgetch(player->curwin);
    switch (choice)
    {
    case KEY_UP: move_up(); break;
    case KEY_DOWN: move_down(); break;
    case KEY_RIGHT: move_right(); break;
    default:
        break;
    }
    return (choice);
}
void display()
{
    player_t *player = player_movement(player->curwin, player->y_loc, player->x_loc, player->character);
    mvwaddch(player->curwin, player->y_loc, player->x_loc, player->character);
}
void borders(void)
{
    int c;
    char pipe = '|';
    char minus = '-';
    initscr();
    cbreak();
    noecho();
    WINDOW *win = newwin(30, 30, 10, 10);
    refresh();

    box(win, (int)pipe, (int)minus);//2d param for right and left. 3d for top and bottom
    wborder(win, (int)pipe, (int)pipe, (int)minus, (int)minus, (int)'+', (int)'+', (int)'+', (int)'+');
    mvwprintw(win, 1, 1, '&');
    wrefresh(win);
}

int main(int ac, char **av)
{
    borders();

    // wrefresh(player->curwin);
    // player = player_movement(player->curwin, 1, 1, '9');
    // while (player->choice > get_mv()) {
    //     display();
    //     wrefresh(player->curwin);
    // }

    endwin();
    return (0);
}