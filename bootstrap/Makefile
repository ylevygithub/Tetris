##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

SRC		=	main.c

OBJ		=	$(SRC:.c=.o)

NAME	=	tetris

all	:	$(NAME)

$(NAME)	:	$(OBJ)
			gcc -o $(NAME) $(OBJ)
clean	:
		rm -f $(NAME)
fclean	:	clean
		rm -f $(OBJ)

re	:	fclean all
