##
## EPITECH PROJECT, 2022
## my_sokoban
## File description:
## Makefile
##

NAME =	my_sokoban

SRC =   src/allocate_array.c	\
		src/open_file.c		\
		src/init_map.c		\
		src/check_all_elmt.c	\
		src/move_npc.c		\
		src/game_loop.c	\
		src/game_over.c			\
		src/errors_handlings.c	\
		src/check_box.c			\
		src/main.c				\
		lib/mini_printf.c		\
		lib/handlings.c			\
		lib/my_strcpy.c			\
		lib/my_strlen.c			\
		lib/my_strcmp.c			\
		lib/my_putstr.c			\
		lib/my_put_nbr.c			\
		lib/my_putchar.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wextra -Wall

all:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(OBJ)	-lncurses
		make clean

clean:
		rm -f $(OBJ)


fclean: clean
		rm -f $(NAME)

re:		fclean all


.PHONY:	all clean fclean re
