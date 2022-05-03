/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:02:24 by gbeauman          #+#    #+#             */
/*   Updated: 2022/05/03 15:35:26 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

static void	print_walls(t_data *img, int index_height, int x, int y)
{
	int	index_width;

	x = 0;
	y = 0;
	index_width = 0;
	img->sprite = mlx_xpm_file_to_image(img->mlx,
			"./asset/sprites/wall.xpm", &img->img_w, &img->img_h);
	while (index_width < img->w)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->sprite, x, y);
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->sprite, x, (img->h - 1) * 52);
		x += 52;
		index_width++;
	}
	y += 52;
	while (index_height < img->h - 1)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->sprite, 0, y);
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->sprite, ((img->w - 1) * 52), y);
		index_height++;
		y += 52;
	}
}

void	print_sprite(t_data *img, int index_height, int index_width)
{
	if (img->map[index_height][index_width] == '1')
		img->sprite = mlx_xpm_file_to_image(img->mlx,
				"./asset/sprites/herbs.xpm", &img->img_w, &img->img_h);
	else if (img->map[index_height][index_width] == '0')
		img->sprite = mlx_xpm_file_to_image(img->mlx,
				"./asset/sprites/grass.xpm", &img->img_w, &img->img_h);
	else if (img->map[index_height][index_width] == 'P')
		img->sprite = mlx_xpm_file_to_image(img->mlx,
				"./asset/sprites/link_front.xpm", &img->img_w, &img->img_h);
	else if (img->map[index_height][index_width] == 'C')
		img->sprite = mlx_xpm_file_to_image(img->mlx,
				"./asset/sprites/ruby.xpm", &img->img_w, &img->img_h);
	else if (img->map[index_height][index_width] == 'E')
		img->sprite = mlx_xpm_file_to_image(img->mlx,
				"./asset/sprites/hole.xpm", &img->img_w, &img->img_h);
	else if (img->map[index_height][index_width] == 'M')
		img->sprite = mlx_xpm_file_to_image(img->mlx,
				"./asset/sprites/enemy.xpm", &img->img_w, &img->img_h);
}

void	print_map(t_data *img)
{
	int	index_height;
	int	index_width;
	int	x;
	int	y;

	x = 52;
	y = 52;
	index_height = 1;
	index_width = 1;
	print_walls(img, index_height, x, y);
	while (index_height < img->h - 1)
	{
		while (index_width < img->w - 1)
		{
			print_sprite(img, index_height, index_width);
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->sprite, x, y);
			x += 52;
			index_width++;
		}
		x = 52;
		y += 52;
		index_width = 1;
		index_height++;
	}
}
