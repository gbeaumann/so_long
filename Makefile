NAME = so_long
CC = gcc
SRC = test.c
FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) :	$(OBJ)
	make -C minilibix
	$(CC) $(FALGS) $(SRC) minilibix/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C minilibix
	rm -f $(OBJ)
fclean: clean
	make clean -C minilibix
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
