##
## EPITECH PROJECT, 2023
## lolo
## File description:
## Makefile
##

SRC	=	src/pars_file.c	\
		src/main.c	\
		src/check_win_lose.c	\
		src/char_word.c	\
		src/my_strlen.c	\
		src/check_char.c	\
		src/random_word.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bob

CPPFLAGS	+=	-I./include/

CFLAGS	+=	-Wall -Wextra

CC	?=	gcc

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

debug:	CFLAGS += -g3
debug:	all

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	re all  clean   fclean  debug
