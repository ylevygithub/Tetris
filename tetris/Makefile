##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

SRC		=	./yac/main.c \
			./yac/print.c \
			./yac/lib.c \
			./yac/lib2.c \
			./yac/lib3.c \
			./yac/my_dirent.c \
			./yac/tetris_check.c \
			./yac/max.c \
			./yac/check.c \
			./yac/flag/flag_debug.c \
			./yac/debug.c \
			./yac/flag/flag_level.c \
			./yac/flag/flag_drop.c \
			./yac/flag/catch_nbr_size.c \
			./yac/flag/flag_left.c \
			./yac/flag/flag_pause.c \
			./yac/flag/flag_quit.c \
			./yac/flag/flag_right.c \
			./yac/flag/flag_size.c \
			./yac/flag/flag_top.c \
			./yac/flag/set_flag.c \
			./yac/set_tetris_in.c \
			./yac/map_creation.c \
			./dav/lib_print.c \
			./dav/open_read.c \
			./dav/set_map.c \
			./dav/str_form.c \
			./dav/tetris_game.c \
			./dav/set.c \
			./dav/verif.c \
			./dav/tetriminos_manip.c \
			./dav/size.c \
			./dav/clean.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

NAME	=	tetris

all	:	$(NAME)

$(NAME)	:	$(OBJ)
			@gcc -o $(NAME) $(OBJ) -lncurses $(CFLAGS)
			clear
			@echo "###COMPILATION DONE###"
clean	:
		@rm -f $(NAME)
fclean	:	clean
		@rm -f $(OBJ)
		@echo "###ALL CLEAN###"
re	:	fclean all
