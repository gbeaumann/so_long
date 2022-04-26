/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:52:05 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/26 14:18:46 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

/*void	find_player(t_anim *move, t_data *img, t_read_map *gnl)
{	
	int	heigth;
	int width;

	
	while ()
}*/

int	player_movement(int keycode, t_data *img)
{
	char	stock;
	int		height;
	int		width;
	
	height = 0;
	width = 0;
	//print_map (img);
	while (height < img->height - 1)
	{
		while (width < img->width - 1)
		{
			if (img->map[height][width] == 'P')
			{
				ft_printf ("test\n");
				if (keycode == 2)
				{
					stock = img->map[height][width];
					img->map[height][width] = img->map[height][width + 1];
					img->map[height][width + 1] = stock;
					mlx_put_image_to_window(img->mlx, img->mlx_window, "./asset/sprites/grass", height * 52, width *52);
					mlx_put_image_to_window(img->mlx, img->mlx_window, "./asset/sprites/link_right", height * 52, (width + 52) *52);
					return (0);
				}
			}
			width++;
		}
		height++;
	}
	return (0);
}