SRC		=	player.c

OBJ		=	$(SRC:.c=.o)

NAME	=	tetris

all :	$(NAME)

$(NAME) :	$(OBJ)
			@gcc -o $(NAME) $(OBJ) -lncurses -g
			clear
			@echo "###COMPILATION DONE###"
clean	:
		@rm -f $(NAME)
fclean	:	clean
		@rm -f $(OBJ)
		@echo "###ALL CLEAN###"
re	:	fclean all
