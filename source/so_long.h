/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:24:59 by gbeauman          #+#    #+#             */
/*   Updated: 2022/05/03 17:31:38 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1

# include	"../minilibix/mlx.h"
# include	"../ft_printf/ft_printf.h"
# include	"../libft/libft.h"
# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<fcntl.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	char	*sprite_path;
	void	*sprite;
	int		bit_per_pixel;
	int		endian;
	int		line_len;
	int		img_w;
	int		img_h;
	char	**map;
	int		h;
	int		w;
	int		ply_h;
	int		ply_w;
	int		coins;
	int		e_h;
	int		e_w;
	int		move_count;
	int		count_pos;
	int		emy_h;
	int		emy_w;
}			t_data;

typedef struct s_read_map
{
	char	backup[BUFFER_SIZE];
	int		pos;
	int		max;
	int		fd;
}			t_read_map;

typedef struct s_find_player
{
	int	height;
	int	width;
}		t_find_player;

void	init_struct(t_data *img);
void	move_count_init(t_data *img);
int		ft_clic_close(t_data *img);
int		ft_close(int keycode, t_data *img);
char	**get_map(t_read_map *gnl, t_data *img);
void	print_map(t_data *img);
void	check_error(t_data *img, t_read_map *gnl, char *map_gnl);
void	check_player(char *map_gnl);
void	check_exit(char *map_gnl);
void	check_coin(char *map_gnl);
void	check_arguments(void);
int		check_map_name(char *name);
void	check_map_composition(char *map_gnl);
int		player_movement(int keycode, t_data *img);
void	coin_collect(t_data *img);
int		player_right(t_data *img);
int		player_down(t_data *img);
int		player_left(t_data *img);
int		player_up(t_data *img);
void	print_sprite(t_data *img, int index_height, int index_width);
int		count_coins(char *gnl_map);
void	destroy_game(t_data *img);
int		find_enemy(t_data *img);
void	check_map_existance(void);
void	map_empty(void);
char	*get_next_line(int fd, t_read_map *gnl, t_data *img);
void	dimention_finder(char *str, t_data *img);
void	keycode_input(t_data *img, int keycode);
void	collect_coin_right(t_data *img);
void	collect_coin_down(t_data *img);
void	collect_coin_left(t_data *img);
void	collect_coin_up(t_data *img);

#endif