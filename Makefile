##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## TasK02 day10
##

SRC = src/main.c \
	src/get_next_line.c \
	src/utils/my_lib.c \
	src/utils/utils.c \
	src/utils/verif_malloc.c \
	src/change_speed.c \
	src/change_dir.c \
	src/utils/free.c \
	src/detect_finish.c \

CFLAGS = -g3 -Iinclude

OBJ = $(SRC:.c=.o)

NAME = ai

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
