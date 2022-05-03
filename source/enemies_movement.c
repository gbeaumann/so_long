/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:44:41 by gbeauman          #+#    #+#             */
/*   Updated: 2022/05/03 15:18:29 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

static int	emy_right(t_data *img)
{
	char	stock;

	if (img->map[img->emy_h][img->emy_w + 1] == 'P')
		destroy_game(img);
	stock = img->map[img->emy_h][img->emy_w];
	img->map[img->emy_h][img->emy_w]
		= img->map[img->emy_h][img->emy_w + 1];
	img->map[img->emy_h][img->emy_w + 1] = stock;
	print_sprite(img, img->emy_h, img->emy_w);
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->sprite, img->emy_w * 52, img->emy_h * 52);
	print_sprite(img, img->emy_h, img->emy_w + 1);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->sprite,
		(img->emy_w + 1) * 52, img->emy_h * 52);
	return (0);
}

static int	emy_left(t_data *img)
{
	char	stock;

	if (img->map[img->emy_h][img->emy_w - 1] == 'P')
		destroy_game(img);
	stock = img->map[img->emy_h][img->emy_w];
	img->map[img->emy_h][img->emy_w]
		= img->map[img->emy_h][img->emy_w - 1];
	img->map[img->emy_h][img->emy_w - 1] = stock;
	print_sprite(img, img->emy_h, img->emy_w);
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->sprite, img->emy_w * 52, img->emy_h * 52);
	print_sprite(img, img->emy_h, img->emy_w - 1);
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->sprite, (img->emy_w - 1) * 52, img->emy_h * 52);
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

	if ((img->map[img->emy_h][img->emy_w + 1] == 'C')
		&& (img->map[img->emy_h][img->emy_w - 1] == 'C'))
		direction = 2;
	else if ((img->map[img->emy_h][img->emy_w + 1] == '1')
		&& (img->map[img->emy_h][img->emy_w - 1] == '1'))
		direction = 2;
	else if ((img->map[img->emy_h][img->emy_w + 1] == 'E')
		&& (img->map[img->emy_h][img->emy_w - 1] == 'E'))
		direction = 2;
	else if ((img->map[img->emy_h][img->emy_w + 1] == 'M')
		&& (img->map[img->emy_h][img->emy_w - 1] == 'M'))
		direction = 2;
	else if (img->map[img->emy_h][img->emy_w + 1] == '1'
		|| img->map[img->emy_h][img->emy_w + 1] == 'E'
		|| img->map[img->emy_h][img->emy_w + 1] == 'C')
		direction = 1;
	else if (img->map[img->emy_h][img->emy_w - 1] == '1'
		|| img->map[img->emy_h][img->emy_w - 1] == 'E'
		|| img->map[img->emy_h][img->emy_w - 1] == 'C')
		direction = 0;
	enemies_movement(img, direction);
}

int	find_enemy(t_data *img)
{
	img->emy_h = 0;
	img->emy_w = 0;
	while (img->emy_h < img->h - 1)
	{
		while (img->emy_w < img->w - 1)
		{
			if (img->map[img->emy_h][img->emy_w] == 'M')
			{
				enemies_direction(img);
				img->emy_w++;
			}
			img->emy_w++;
		}
		img->emy_w = 0;
		img->emy_h++;
	}
	return (0);
}
