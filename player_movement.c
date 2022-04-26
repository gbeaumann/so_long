/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:52:05 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/26 20:21:55 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	find_player(t_data *img)
{
	while (img->player_height < img->height - 1)
		{
			while (img->player_width < img->width - 1)
			{
				if (img->map[img->player_height][img->player_width] == 'P')
					return(0);
				img->player_width++;
			}
			img->player_width = 0;
			img->player_height++;
		}
	return (0);
}

int	player_movement(int keycode, t_data *img)
{
	char	stock;
	
	img->player_height = 0;
	img->player_width = 0;
	find_player(img);
	if (img->mlx != NULL && keycode == 2)
	{
		stock = img->map[img->player_height][img->player_width];
		img->map[img->player_height][img->player_width] = img->map[img->player_height][img->player_width + 1];
		img->map[img->player_height][img->player_width + 1] = stock;
		ft_printf ("height: %d\n", img->player_height);
		ft_printf ("width: %d\n", img->player_width);
		ft_printf ("%c\n", img->map[img->player_height][img->player_width]);
		print_sprite(img, img->player_height, img->player_width);
		mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, img->player_width * 52, img->player_height *52);
		ft_printf ("%c\n", img->map[img->player_height][img->player_width + 1]);
		print_sprite(img, img->player_height, img->player_width + 1);
		mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, (img->player_width + 1) *52, img->player_height *52);
		return (0);
	}
	ft_printf ("plop\n");
	return (0);
}