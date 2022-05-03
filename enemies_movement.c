/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:44:41 by gbeauman          #+#    #+#             */
/*   Updated: 2022/05/03 11:50:11 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

static int	emy_right(t_data *img)
{
	char	stock;

	if (img->map[img->emy_height][img->emy_width + 1] == 'P')
		destroy_game(img);
	stock = img->map[img->emy_height][img->emy_width];
	img->map[img->emy_height][img->emy_width]
		= img->map[img->emy_height][img->emy_width + 1];
	img->map[img->emy_height][img->emy_width + 1] = stock;
	print_sprite(img, img->emy_height, img->emy_width);
	mlx_put_image_to_window(img->mlx, img->mlx_window,
		img->sprite, img->emy_width * 52, img->emy_height * 52);
	print_sprite(img, img->emy_height, img->emy_width + 1);
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite,
		(img->emy_width + 1) * 52, img->emy_height * 52);
	return (0);
}

static int	emy_left(t_data *img)
{
	char	stock;

	if (img->map[img->emy_height][img->emy_width - 1] == 'P')
		destroy_game(img);
	stock = img->map[img->emy_height][img->emy_width];
	img->map[img->emy_height][img->emy_width]
		= img->map[img->emy_height][img->emy_width - 1];
	img->map[img->emy_height][img->emy_width - 1] = stock;
	print_sprite(img, img->emy_height, img->emy_width);
	mlx_put_image_to_window(img->mlx, img->mlx_window,
		img->sprite, img->emy_width * 52, img->emy_height * 52);
	print_sprite(img, img->emy_height, img->emy_width - 1);
	mlx_put_image_to_window(img->mlx, img->mlx_window,
		img->sprite, (img->emy_width - 1) * 52, img->emy_height * 52);
	return (0);
}

int	enemies_movement(t_data *img, int direction)
{
	if (direction == 0)
		emy_right(img);
	else if (direction == 1)
		emy_left(img);
	else
		return (0);
	return (0);
}

void	enemies_direction(t_data *img)
{
	static int	direction = 0;

	if ((img->map[img->emy_height][img->emy_width + 1] == 'C')
		&& (img->map[img->emy_height][img->emy_width - 1] == 'C'))
		direction = 2;
	else if ((img->map[img->emy_height][img->emy_width + 1] == '1')
		&& (img->map[img->emy_height][img->emy_width - 1] == '1'))
		direction = 2;
	else if ((img->map[img->emy_height][img->emy_width + 1] == 'E')
		&& (img->map[img->emy_height][img->emy_width - 1] == 'E'))
		direction = 2;
	else if ((img->map[img->emy_height][img->emy_width + 1] == 'M')
		&& (img->map[img->emy_height][img->emy_width - 1] == 'M'))
		direction = 2;
	else if (img->map[img->emy_height][img->emy_width + 1] == '1'
		|| img->map[img->emy_height][img->emy_width + 1] == 'E'
		|| img->map[img->emy_height][img->emy_width + 1] == 'C')
		direction = 1;
	else if (img->map[img->emy_height][img->emy_width - 1] == '1'
		|| img->map[img->emy_height][img->emy_width - 1] == 'E'
		|| img->map[img->emy_height][img->emy_width - 1] == 'C')
		direction = 0;
	enemies_movement(img, direction);
}

int	find_enemy(t_data *img)
{
	img->emy_height = 0;
	img->emy_width = 0;
	while (img->emy_height < img->height - 1)
	{
		while (img->emy_width < img->width - 1)
		{
			if (img->map[img->emy_height][img->emy_width] == 'M')
			{
				enemies_direction(img);
				img->emy_width++;
			}
			img->emy_width++;
		}
		img->emy_width = 0;
		img->emy_height++;
	}
	return (0);
}
