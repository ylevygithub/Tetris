/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** my.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ncurses.h>
#include <curses.h>
#include <time.h>
#include <dirent.h>

typedef struct s_terminal_size
{
    int x;
    int y;
    int save_x;
    int save_y;
} t_terminal_size;

struct tetris_s {
    char **map;
    char *buff;
    char *new_buff;
    char *name;
    int fd;
    int size;
    char *str;
};
typedef struct tetris_s tetris_t;

struct figure_s {
    char **figure;
};
typedef struct figure_s figure_t;

struct tetris_in_s {
    int x;
    int y;
    int line;
    int column;
    int column_min;
    int column_max;
    int line_max;
    char **fig;
};
typedef struct tetris_in_s tetris_in_t;

struct tetris_creation_s {
    int end_x;
    int end_y;
};
typedef struct tetris_creation_s tetris_creation_t;

struct game_info_s
{
    char **map;
    int total;
    int score;
    int lvl;
    int in;
};
typedef struct game_info_s game_info_t;

struct flag_s
{
    int col;
    int row;
    char *pause;
    char *quit;
    char *drop;
    char *top;
    char *right;
    char *left;
    int level;
};
typedef struct flag_s flag_t;

/*my_dirent.c*/
int reg_cas(struct dirent **directory, DIR *rep);
int my_count_dirent(char *str);

/*tetris_check.c*/
int error_file(char **tab);
int tetri_cheak(struct dirent **directory);
int my_tetri_cheak(void);
int check_tetrimino(char *path);
char *complet(char *str);

/*max.c*/
int col_max(char **tab);
int line_max(char **tab);

/*check.c*/
int check_arg(int ac, char **av);
int check_av(char **av);
int ckeck_null(tetris_t *tetris);

/*debug.c*/
void debug_mode(char **av);
int debug_mode_part(flag_t *flag);

/*lib.c*/
void my_putchar(char c);
void my_putstr(char *str);
void my_putstr_error(char *str);
void my_putmap(char **map);
void my_putmap_in_fd(char **map, int fd);

/*lib2.c*/
int my_putnbr(int nb);
int my_getnbr(char *str);
void my_putstr_in_fd(char *str, int fd);
char *my_charcpy(char c);
void my_put_name(char *str);

/*lib3.c*/
void my_show_tetrimino(char **map);
char **set_tab(char *path);
int is_numorspace(char c);

/*map_creation.c*/
void my_put_tetris_in_file(char **map, int fd, int i, int end_x);
char **map_create_part(char **map, tetris_creation_t tetris, int i, int j);
char **map_create(char **map, tetris_creation_t tetris);
void all(char **av);

/*print.c*/
void set_start_rep(char *rep);
void print_usage(void);

/*set_in_tetris.c*/
tetris_t *init_tetris(void);
int count_valid(struct dirent **directory);
tetris_in_t *set_in_struct(char const *pathname);
tetris_in_t **in_struct(struct dirent **directory);
int error(char *path);


/*--------folder/flag--------*/
/*set_flag.c*/
flag_t *set_flag_struct(char **av);
/*flag_drop.c*/
int find_drop2(char **av, int i, int j);
int find_drop(char **av);
char *flag_drop(char **av);
/*flag_left.c*/
int find_left2(char **av, int i, int j);
int find_left(char **av);
char *flag_left(char **av);
/*flag_level.c*/
int find_level2(char **av, int i, int j);
int find_level(char **av);
int flag_level(char **av);
/*flag_pause.c*/
int find_pause2(char **av, int i, int j);
int find_pause(char **av);
char *pause_restart(char **av);
/*flag_quit.c*/
int find_quit2(char **av, int i, int j);
int find_quit(char **av);
char *flag_quit(char **av);
/*flag_right.c*/
int find_right2(char **av, int i, int j);
int find_right(char **av);
char *flag_right(char **av);
/*flag_size.c*/
int find_size2(char **av, int i, int j);
int find_size(char **av);
int map_size_row(char **av);
int map_size_col(char **av);
/*catch_nbr_size.c*/
char *number_str(char *str, int i);
char *number_str2(char *str, int i);
/*flag_top.c*/
int find_top2(char **av, int i, int j);
int find_top(char **av);
char *flag_top(char **av);
/*flag_debug.c*/
int find_debug2(char **av, int i, int j);
int find_debug(char **av);
int flag_debug(char **av);

/*lib_print.c*/
int my_strlen(char *str);
char *my_strcpy(char *str);
char **my_tabcpy(char **tab);
void print_tab(char **map, int line_size, t_terminal_size *terminal);
void my_print_tab_window(t_terminal_size *terminal, game_info_t *game);

/*clean.c*/
void down_all_line(game_info_t *game, char **copy, int y);
int line_full(char *str);
int clean_line(game_info_t *game);

/*open_read.c*/
char *my_open_read(const char *path);
char **tab_form(const char *pathname);
char **game_map1(const char *pathname);

/*set_map.c*/
int verif_char(char c);
int mon_compteur(char *str);
int my_wordlen(char *str, int i);
char **my_str_to_word_array(char *str);

/*set.c*/
game_info_t *set_struct_game(char **map, int x);
void set_tetri_on_map(tetris_in_t *in, game_info_t *game);
void set_terminal_info(t_terminal_size *terminal, char **map);
t_terminal_size *init_terminal(game_info_t *game);

/*size.c*/
int line_size_tab(char **tab);
int column_size_tab(char **tab);

/*str_form.c*/
int count_to_first(char *str);
int my_count(char *str);
int my_col_size(char *str, int i);
char **str_form(char *str);
int str_form_part(char *str, int a);

/*tetriminos_manip.c*/
void delet_form_in(tetris_in_t *in, game_info_t *game);
int down_tetrimino(tetris_in_t *in, game_info_t *game,
t_terminal_size *terminal);
int right_tetrimino(tetris_in_t *in, game_info_t *game,
t_terminal_size *terminal);
int left_tetrimino(tetris_in_t *in, game_info_t *game,
t_terminal_size *terminal);

/*verif.c*/
int verif_touch_down(tetris_in_t *in, game_info_t *game);
int verif_touch_right(tetris_in_t *in, game_info_t *game);
int verif_touch_left(tetris_in_t *in, game_info_t *game);
void verif_action(tetris_in_t **in, game_info_t *game,
t_terminal_size *terminal);
int verif_line_loose(char *str, int size);

/*tetris_game.c*/
int my_rand(int x);
int loose_condition(tetris_in_t *in, game_info_t *game);
float my_clock(clock_t start_t, game_info_t *game, t_terminal_size *terminal,
tetris_in_t **in);
void game_loop(tetris_in_t **in, game_info_t *game, t_terminal_size *terminal);
int tetris_game(char **map);
