##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/pars_file.c \
		src/main.c      \
		src/my_strlen.c \
		src/error_n_game.c      \
		src/check_char.c	\
		src/game.c      \
		src/random_word.c

OBJ	=	$(SRC:.c=.o)

NAME	=	hangman

CPPFLAGS =	-I./include/

CFLAGS =	-Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS)

debug:	CFLAGS += -g3
debug:	all

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	re all  clean   fclean  debug
