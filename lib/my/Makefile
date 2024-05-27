##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =	my_compute_power_rec.c	\
			my_putchar.c	\
			my_putstr.c	\
			my_strlen.c	\
			str_to_int.c	\
			my_strcpy.c

OBJ     =	$(SRC:.c=.o)

NAME    =	libmy

CPPFLAGS	=	-I./include

all:    $(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME).a $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME).a

re:     fclean all
