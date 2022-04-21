# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 09:30:37 by gbeauman          #+#    #+#              #
#    Updated: 2021/11/25 11:28:46 by gbeauman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
CC = gcc
SRC = ft_printf.c\
	  ft_check.c\
	  ft_print_s.c\
	  ft_print_c.c\
	  ft_print_num.c\
	  ft_putnbr.c\
	  ft_print_u.c\
	  ft_putnbr_u.c\
	  ft_putnbr_x.c\
	  ft_print_x.c\
	  ft_putnbr_mx.c\
	  ft_print_mx.c\
	  ft_print_p.c\
	  ft_putnbr_p.c\
	  ft_print_ui.c
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
