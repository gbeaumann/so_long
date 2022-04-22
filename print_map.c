/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:02:24 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/22 14:00:28 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

/*static void	print_walls(t_data *img, t_read_map *gnl)
{
	int	height;

	height = 0;
	while (len < img->img_width)
	{
	
	}
	while (img->map[height])
	{
		
	}
}*/

static void	print_sprite(t_data *img, int index_height, int index_width)
{
	if (img->map[index_height][index_width] == '1')
		img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/herbs.xpm", &img->img_height, &img->img_height);
	else if (img->map[index_height][index_width] == '0')
		img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/grass.xpm", &img->img_height, &img->img_height);
	else if (img->map[index_height][index_width] == 'P')
		img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/link_front.xpm", &img->img_height, &img->img_height);
	else if (img->map[index_height][index_width] == 'C')
		img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/ruby.xpm", &img->img_height, &img->img_height);
	else if (img->map[index_height][index_width] == 'E')
		img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/exit.xpm", &img->img_height, &img->img_height);
}
void	print_map(t_data *img, t_read_map *gnl)
{
	int	index_height;
	int	index_width;
	int	x;
	int	y;
	
	x = 52;
	y = 52;
	index_height = 1;
	index_width = 1;
	while (index_height < gnl->height - 1)
	{
		while (index_width < gnl->width - 1)
		{
			print_sprite(img, index_height, index_width);
			mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, x, y);
			x += 52;
			index_width++;
		}
		x = 0;
		y += 52;
		index_width = 0;
		index_height++;
	}
}