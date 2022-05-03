/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:52:30 by gbeauman          #+#    #+#             */
/*   Updated: 2022/05/03 17:05:19 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	coin_collect(t_data *img)
{
	print_sprite(img, img->ply_h, img->ply_w);
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->sprite, img->ply_w * 52, img->ply_h * 52);
	img->coins--;
	img->move_count++;
	ft_printf("Move count: %d\n", img->move_count);
}

int	player_right(t_data *img)
{
	char	stock;

	if (img->map[img->ply_h][img->ply_w + 1] == '1'
		|| img->map[img->ply_h][img->ply_w + 1] == 'E')
		return (0);
	stock = img->map[img->ply_h][img->ply_w];
	img->map[img->ply_h][img->ply_w] = img->map[img->ply_h][img->ply_w + 1];
	img->map[img->ply_h][img->ply_w + 1] = stock;
	if (img->map[img->ply_h][img->ply_w] == 'C')
	{
		collect_coin_right(img);
		return (0);
	}
	print_sprite(img, img->ply_h, img->ply_w);
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->sprite, img->ply_w * 52, img->ply_h * 52);
	img->sprite = mlx_xpm_file_to_image(img->mlx,
			"./asset/sprites/link_right.xpm", &img->img_w, &img->img_h);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->sprite,
		(img->ply_w + 1) * 52, img->ply_h * 52);
	find_enemy(img);
	img->move_count++;
	ft_printf("Move count: %d\n", img->move_count);
	return (0);
}

int	player_down(t_data *img)
{
	char	stock;

	if (img->map[img->ply_h + 1][img->ply_w] == '1'
		|| img->map[img->ply_h + 1][img->ply_w] == 'E')
		return (0);
	stock = img->map[img->ply_h][img->ply_w];
	img->map[img->ply_h][img->ply_w] = img->map[img->ply_h + 1][img->ply_w];
	img->map[img->ply_h + 1][img->ply_w] = stock;
	if (img->map[img->ply_h][img->ply_w] == 'C')
	{
		collect_coin_down(img);
		return (0);
	}
	print_sprite(img, img->ply_h, img->ply_w);
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->sprite, img->ply_w * 52, img->ply_h * 52);
	img->sprite = mlx_xpm_file_to_image(img->mlx,
			"./asset/sprites/link_front.xpm", &img->img_w, &img->img_h);
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->sprite, img->ply_w * 52, (img->ply_h + 1) * 52);
	find_enemy(img);
	img->move_count++;
	ft_printf("Move count: %d\n", img->move_count);
	return (0);
}

int	player_left(t_data *img)
{
	char	stock;

	if (img->map[img->ply_h][img->ply_w - 1] == '1'
		|| img->map[img->ply_h][img->ply_w - 1] == 'E')
		return (0);
	stock = img->map[img->ply_h][img->ply_w];
	img->map[img->ply_h][img->ply_w] = img->map[img->ply_h][img->ply_w - 1];
	img->map[img->ply_h][img->ply_w - 1] = stock;
	if (img->map[img->ply_h][img->ply_w] == 'C')
	{
		collect_coin_left(img);
		return (0);
	}
	print_sprite(img, img->ply_h, img->ply_w);
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->sprite, img->ply_w * 52, img->ply_h * 52);
	img->sprite = mlx_xpm_file_to_image(img->mlx,
			"./asset/sprites/link_left.xpm", &img->img_w, &img->img_h);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->sprite,
		(img->ply_w - 1) * 52, img->ply_h * 52);
	find_enemy(img);
	img->move_count++;
	ft_printf("Move count: %d\n", img->move_count);
	return (0);
}

int	player_up(t_data *img)
{
	char	stock;

	if (img->map[img->ply_h - 1][img->ply_w] == '1'
		|| img->map[img->ply_h - 1][img->ply_w] == 'E')
		return (0);
	stock = img->map[img->ply_h][img->ply_w];
	img->map[img->ply_h][img->ply_w] = img->map[img->ply_h - 1][img->ply_w];
	img->map[img->ply_h - 1][img->ply_w] = stock;
	if (img->map[img->ply_h][img->ply_w] == 'C')
	{
		collect_coin_up(img);
		return (0);
	}
	print_sprite(img, img->ply_h, img->ply_w);
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->sprite, img->ply_w * 52, img->ply_h * 52);
	img->sprite = mlx_xpm_file_to_image(img->mlx,
			"./asset/sprites/link_back.xpm", &img->img_w, &img->img_h);
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->sprite, img->ply_w * 52, (img->ply_h - 1) * 52);
	find_enemy(img);
	img->move_count++;
	ft_printf("Move count: %d\n", img->move_count);
	return (0);
}
