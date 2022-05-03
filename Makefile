NAME =	so_long
CC =	gcc
SRC =	get_next_line.c\
		window.c\
		print_map.c\
		check_error.c\
		check_error_2.c\
		check_error_3.c\
		player_movement.c\
		player_movement_2.c\
		player_movement_extra.c\
		extra_fonctions.c\
		enemies_movement.c\
		main.c
FLAGS =	-Wall -Werror -Wextra
OBJ =	$(SRC:.c=.o)

all: $(NAME)

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
