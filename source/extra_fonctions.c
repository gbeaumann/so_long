/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:45:34 by gbeauman          #+#    #+#             */
/*   Updated: 2022/05/03 15:20:14 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	init_struct(t_data *img)
{
	img->img_h = 52;
	img->img_w = 52;
	img->e_h = 0;
	img->e_w = 0;
	img->coins = 0;
	img->move_count = 0;
	img->mlx = mlx_init();
}

void	dimention_finder(char *map_gnl, t_data *img)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = 0;
	height = 0;
	while (map_gnl[i])
	{
		if (map_gnl[i] == '\n')
		{
			height++;
			i++;
			width = 0;
		}
		i++;
		width++;
	}
	height++;
	img->w = width;
	img->h = height;
}

int	count_coins(char *gnl_map)
{
	int	i;
	int	coins;

	i = 0;
	coins = 0;
	while (gnl_map[i])
	{
		if (gnl_map[i] == 'C')
			coins++;
		i++;
	}
	return (coins);
}

void	destroy_game(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit(0);
}

void	move_count_init(t_data *img)
{
	mlx_string_put(img->mlx, img->mlx_win,
		img->count_pos - 40, 30, 0x00ffff00, "Move: ");
	mlx_string_put(img->mlx, img->mlx_win,
		img->count_pos, 30, 0x00ffff00, "0");
	ft_printf ("Move count: 0\n");
}
