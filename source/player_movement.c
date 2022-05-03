/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:52:05 by gbeauman          #+#    #+#             */
/*   Updated: 2022/05/03 16:49:03 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	find_player(t_data *img)
{
	while (img->ply_h < img->h - 1)
	{
		while (img->ply_w < img->w - 1)
		{
			if (img->map[img->ply_h][img->ply_w] == 'P')
				return (0);
			img->ply_w++;
		}
		img->ply_w = 0;
		img->ply_h++;
	}
	return (0);
}

void	new_exit(t_data *img)
{
	while (img->e_h < img->h - 1)
	{
		while (img->e_w < img->w - 1)
		{
			if (img->map[img->e_h][img->e_w] == 'E')
			{
				img->sprite = mlx_xpm_file_to_image(img->mlx,
						"./asset/sprites/exit.xpm", &img->img_w, &img->img_h);
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->sprite, img->e_w * 52, img->e_h * 52);
			}
			img->e_w++;
		}
		img->e_w = 0;
		img->e_h++;
	}
}

void	exit_window(int keycode, t_data *img)
{
	if (keycode == 2 || keycode == 124)
	{
		if (img->map[img->ply_h][img->ply_w + 1] == 'E')
			destroy_game(img);
	}
	else if (keycode == 1 || keycode == 125)
	{
		if (img->map[img->ply_h + 1][img->ply_w] == 'E')
			destroy_game(img);
	}
	if (keycode == 0 || keycode == 123)
	{
		if (img->map[img->ply_h][img->ply_w - 1] == 'E')
			destroy_game(img);
	}
	if (keycode == 13 || keycode == 126)
	{
		if (img->map[img->ply_h - 1][img->ply_w] == 'E')
			destroy_game(img);
	}
}

void	monster_encounter(int keycode, t_data *img)
{
	if (keycode == 2)
	{
		if (img->map[img->ply_h][img->ply_w + 1] == 'M')
			destroy_game(img);
	}
	else if (keycode == 1)
	{
		if (img->map[img->ply_h + 1][img->ply_w] == 'M')
			destroy_game(img);
	}
	if (keycode == 0)
	{
		if (img->map[img->ply_h][img->ply_w - 1] == 'M')
			destroy_game(img);
	}
	if (keycode == 13)
	{
		if (img->map[img->ply_h - 1][img->ply_w] == 'M')
			destroy_game(img);
	}
}

int	player_movement(int keycode, t_data *img)
{	
	char	*count_move;

	img->ply_h = 0;
	img->ply_w = 0;
	find_player(img);
	monster_encounter(keycode, img);
	if (img->coins == 0)
	{
		new_exit(img);
		exit_window(keycode, img);
	}
	keycode_input(img, keycode);
	count_move = ft_itoa(img->move_count);
	img->sprite = mlx_xpm_file_to_image(img->mlx,
			"./asset/sprites/wall.xpm", &img->img_w, &img->img_h);
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->sprite, img->count_pos, 0);
	mlx_string_put(img->mlx, img->mlx_win,
		img->count_pos, 30, 0x00ffff00, count_move);
	return (0);
}
