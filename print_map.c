/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:02:24 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/21 16:11:01 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	print_map(t_data *img, t_read_map *gnl)
{
	int	index_height;
	int	index_width;
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	index_height = 0;
	index_width = 0;
	while (index_height < gnl->height)
	{
		ft_printf("height\n");
		while (index_width < gnl->width)
		{
			ft_printf("width\n");
			if (img->map[index_height][index_width] == '1')
			{
				ft_printf("wall\n");
				img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/wall.xpm", &img->img_height, &img->img_height);
				//mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, x, y);
			}
			else if (img->map[index_height][index_width] == '0')
			{
				ft_printf("grass\n");
				img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/grass.xpm", &img->img_height, &img->img_height);
				//mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, x, y);
			}
			else if (img->map[index_height][index_width] == 'P')
			{
				ft_printf("player\n");
				img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/link_front.xpm", &img->img_height, &img->img_height);
				//mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, x, y);
			}
			else if (img->map[index_height][index_width] == 'C')
			{
				ft_printf("ruby\n");
				img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/ruby.xpm", &img->img_height, &img->img_height);
				//mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, x, y);
			}
			else if (img->map[index_height][index_width] == 'E')
			{
				ft_printf("exit\n");
				img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/exit.xpm", &img->img_height, &img->img_height);
				//mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, x, y);
			}
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