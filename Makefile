##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## TasK02 day10
##

SRC = src/main.c \
	src/get_next_line.c \
	src/my_lib.c \
	src/utils.c \
	src/verif_malloc.c \
	src/change_speed_dir.c \
	src/free.c \

CFLAGS = -g3 -Iinclude

OBJ = $(SRC:.c=.o)

NAME = ia

GCCWAY = gcc -o

all: $(NAME)

$(NAME): $(OBJ)
	$(GCCWAY) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
