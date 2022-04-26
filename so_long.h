/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:24:59 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/26 18:54:30 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1

# include	"./minilibix/mlx.h"
# include	"./ft_printf/ft_printf.h"
# include	"./libft/libft.h"
# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<fcntl.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_window;
	char	*sprite_path;
	void	*sprite;
	int		bit_per_pixel;
	int		endian;
	int		line_length;
	int		img_width;
	int		img_height;
	char	**map;
	int		height;
	int		width;
	int		player_height;
	int		player_width;
}			t_data;

typedef struct	s_read_map
{
	char	backup[BUFFER_SIZE];
	int		pos;
	int		max;
	int		fd;
//	int		height;
//	int		width;
}			t_read_map;

typedef struct s_find_player
{
	int height;
	int width;
}		t_find_player;


int		ft_clic_close(t_data *img);
int		ft_close(int keycode, t_data *img);
char	**get_map(t_read_map *gnl, t_data *img);
void	print_map(t_data *img, t_find_player *player);
void	check_error(t_data *img, t_read_map *gnl, char *map_gnl);
void	check_player(char *map_gnl);
void	check_exit(char *map_gnl);
int		player_movement(int keycode, t_data *img);
void	print_sprite(t_data *img, int index_height, int index_width);
char	*get_next_line(int fd, t_read_map *gnl, t_data *img);

#endif