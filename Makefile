NAME =	so_long
CC =	gcc
SRC =	./source/get_next_line.c\
		./source/window.c\
		./source/print_map.c\
		./source/check_error.c\
		./source/check_error_2.c\
		./source/check_error_3.c\
		./source/player_movement.c\
		./source/player_movement_2.c\
		./source/player_movement_extra.c\
		./source/extra_fonctions.c\
		./source/enemies_movement.c\
		./source/main.c
FLAGS =	-Wall -Werror -Wextra
OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME) :	$(OBJ)
	make -C minilibix
	make -C ft_printf
	make -C libft
	$(CC) $(FALGS) $(SRC) minilibix/libmlx.a ft_printf/libftprintf.a libft/libft.a -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(NAME)

$(NAME) :	$(OBJ)
	make -C minilibix
	make -C ft_printf
	make -C libft
	$(CC) $(FALGS) $(SRC) minilibix/libmlx.a ft_printf/libftprintf.a libft/libft.a -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C minilibix
	make clean -C ft_printf
	make clean -C libft
	rm -f $(OBJ)
fclean: clean
	make clean -C minilibix
	make fclean -C ft_printf
	make fclean	-C libft
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
