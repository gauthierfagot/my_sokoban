##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =	main.c	\
			error_handling.c	\
			create_buffer.c	\
			create_array.c	\
			add_to_struct.c	\
			free_variable.c	\
			display_map.c	\
			move_param.c	\
			check_stat_game.c

OBJ     =	$(SRC:.c=.o)

NAME    =	my_sokoban

CPPFLAGS	=	-I./include

LDFLAGS	=	-L./lib/my -lmy -lncurses

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my libmy
	make -C ./lib/my clean
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
