/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_extra.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:45:38 by gbeauman          #+#    #+#             */
/*   Updated: 2022/05/03 17:05:47 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	keycode_input(t_data *img, int keycode)
{
	if (img->mlx != NULL && (keycode == 2 || keycode == 124))
		player_right(img);
	else if (img->mlx != NULL && (keycode == 1 || keycode == 125))
		player_down(img);
	else if (img->mlx != NULL && (keycode == 0 || keycode == 123))
		player_left(img);
	else if (img->mlx != NULL && (keycode == 13 || keycode == 126))
		player_up(img);
}

void	collect_coin_right(t_data *img)
{
	img->map[img->ply_h][img->ply_w] = '0';
	coin_collect(img);
	img->sprite = mlx_xpm_file_to_image(img->mlx,
			"./asset/sprites/link_right.xpm", &img->img_w, &img->img_h);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->sprite,
		(img->ply_w + 1) * 52, img->ply_h * 52);
	find_enemy(img);
}

void	collect_coin_down(t_data *img)
{
	img->map[img->ply_h][img->ply_w] = '0';
	coin_collect(img);
	img->sprite = mlx_xpm_file_to_image(img->mlx,
			"./asset/sprites/link_front.xpm", &img->img_w, &img->img_h);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->sprite,
		img->ply_w * 52, (img->ply_h + 1) * 52);
	find_enemy(img);
}

void	collect_coin_left(t_data *img)
{
	img->map[img->ply_h][img->ply_w] = '0';
	coin_collect(img);
	img->sprite = mlx_xpm_file_to_image(img->mlx,
			"./asset/sprites/link_left.xpm", &img->img_w, &img->img_h);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->sprite,
		(img->ply_w - 1) * 52, img->ply_h * 52);
	find_enemy(img);
}

void	collect_coin_up(t_data *img)
{
	img->map[img->ply_h][img->ply_w] = '0';
	coin_collect(img);
	img->sprite = mlx_xpm_file_to_image(img->mlx,
			"./asset/sprites/link_back.xpm", &img->img_w, &img->img_h);
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->sprite, img->ply_w * 52, (img->ply_h - 1) * 52);
	find_enemy(img);
}
