#include "my.h"
#include <stdarg.h>
void hello_world(void)
{
    //initialise the screen
    //sets up memory and clears the screen
    initscr();
    //prints a string (const char *) to a window
    printw("Hello world!");
    //refreshes the screen to match whats in memory
    refresh();
    //whats for user input, returns int value of that key
    int c = getch();

    printw("%d", c);

    getch();
    //dealocates memory and end ncurses.
    endwin();
}
void moving_cursor(void)
{
    int x, y = 10;
    initscr();
//     move(y, x);
//     printw("Hello world!");
//prints the string at 10:10 from the top
    mvprintw(y, x, "helloworld!");
    refresh();
    int c = getch();
    //if you want to clear the screen after hello world and before printing the key
    clear();
    //prints the input user at the top
    mvprintw(0, 0, "%d", c);
    //instead of -->// move(0, 0);// printw("%d", c);
    getch();
    endwin();
}
void window_create(void)
{
    int c;
    int height = 10;
    int width = 20;
    int start_x = 10;
    int start_y = 10;
    initscr();
    WINDOW *win = newwin(height, width, start_y, start_x);
    refresh();

    //create a box in that win.
    box(win, 0, 0);
    //print in the box
//    wprintw(win, "This is my box");
    mvwprintw(win, 1, 1, "This is my box");
    wrefresh(win);
    c = getch();
    getch();
    endwin();
    return (0);
}
void borders(void)
{
    int c;
    char pipe = '|';
    char minus = '-';
    initscr();
    //usefull for testing
    cbreak();
    //doesnt print the getch
    noecho();
    WINDOW *win = newwin(10, 20, 10, 10);
    refresh();

    //create a box in that win without the ability to manage the corners.
    box(win, (int)pipe, (int)minus);//2d param for right and left. 3d for top and bottom
//example--> wborder(win, left, right, top, bottom, tlc, trc, blc, brc);
    wborder(win, (int)pipe, (int)pipe, (int)minus, (int)minus, (int)'+', (int)'+', (int)'+', (int)'+');
    mvwprintw(win, 1, 1, "This is my box");
    wrefresh(win);
    c = getch();
    getch();
    endwin();

}
void attributes_colors()
{
    /*
    COLOR_PAIR(n)
    COLOR_BALCK     0
    COLOR_RED       1
    COLOR_GREEN     2
    COLOR_YELLOW    3
    COLOR_BLUE      4
    COLOR_MAGENTA   5
    COLOR_CYAN      6
    COLOR_WHITE     7
    */
    initscr();
    start_color();
    init_pair(1, 1, 4);//1d param for init, 2d for color the text, 3d for the font of the text
    attron(COLOR_PAIR(1));
    printw("salut mon chou");
    attroff(COLOR_PAIR(1));
    getch();
    endwin();
}
void user_input()
{
    initscr();
    cbreak();
    noecho();
    //get screen size
    int y_max;
    int x_max;
    getmaxyx(stdscr, y_max, x_max);

    //create a window for our input
    WINDOW *win = newwin(10, x_max-20, y_max-10, 10);
    box(win, 0, 0);
    refresh();
    wrefresh(win);

    keypad(win, true);

    int c = wgetch(win);
    while (win){
        if (c == KEY_UP) {
            mvwprintw(win, 1, 1, "You pressed UP!");
            wrefresh(win);
        }
        else if (c == KEY_DOWN) {
            mvwprintw(win, 1, 1, "You pressed Down!");
            wrefresh(win);
        }
        else if (c == KEY_LEFT) {
            mvwprintw(win, 1, 1, "You pressed LEFT!");
            wrefresh(win);
        }
    }
    //make sure programs wait before exiting..
    getch();
    endwin();
}
int main(int ac, char **av)
{
    user_input();
}