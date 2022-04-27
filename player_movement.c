/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:52:05 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/27 15:36:03 by gbeauman         ###   ########.fr       */
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

void	new_exit(t_data *img)
{
	img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/exit.xpm", &img->img_height, &img->img_height);
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, img->exit_width * 52, img->exit_height * 52);
}

int	find_exit(t_data *img)
{
	while (img->exit_height < img->height - 1)
		{
			while (img->exit_width < img->width - 1)
			{
				if (img->map[img->exit_height][img->exit_width] == 'E')
					return(0);
				img->exit_width++;
			}
			img->exit_width = 0;
			img->exit_height++;
		}
	return (0);
}

void	coin_collect(t_data *img)
{
	print_sprite(img, img->player_height, img->player_width);
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, img->player_width * 52, img->player_height * 52);
	img->coins--;
}

static int player_right(t_data *img)
{
	char	stock;
	
	if (img->map[img->player_height][img->player_width + 1] == '1' || img->map[img->player_height][img->player_width + 1] == 'E')
		return (0);
	stock = img->map[img->player_height][img->player_width];
	img->map[img->player_height][img->player_width] = img->map[img->player_height][img->player_width + 1];
	img->map[img->player_height][img->player_width + 1] = stock;
	if (img->map[img->player_height][img->player_width] == 'C')
	{
		img->map[img->player_height][img->player_width] = '0';
		coin_collect(img);
		img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/link_right.xpm", &img->img_height, &img->img_height);
		mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, (img->player_width + 1) * 52, img->player_height * 52);
		return (0);
	}
	print_sprite(img, img->player_height, img->player_width);
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, img->player_width * 52, img->player_height * 52);
	img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/link_right.xpm", &img->img_height, &img->img_height);
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, (img->player_width + 1) * 52, img->player_height * 52);
	return (0);
}

static int player_down(t_data *img)
{
	char	stock;
	
	if (img->map[img->player_height + 1][img->player_width] == '1' || img->map[img->player_height + 1][img->player_width] == 'E')
		return (0);
	stock = img->map[img->player_height][img->player_width];
	img->map[img->player_height][img->player_width] = img->map[img->player_height + 1][img->player_width];
	img->map[img->player_height + 1][img->player_width] = stock;
	if (img->map[img->player_height][img->player_width] == 'C')
	{
		img->map[img->player_height][img->player_width] = '0';
		coin_collect(img);
		img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/link_front.xpm", &img->img_height, &img->img_height);
		mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, img->player_width * 52, (img->player_height + 1) * 52);
		return (0);
	}
	print_sprite(img, img->player_height, img->player_width);
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, img->player_width * 52, img->player_height * 52);
	img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/link_front.xpm", &img->img_height, &img->img_height);
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, img->player_width * 52, (img->player_height + 1) * 52);
	return (0);
}

static int player_left(t_data *img)
{
	char	stock;
	
	if (img->map[img->player_height][img->player_width - 1] == '1' || img->map[img->player_height][img->player_width - 1] == 'E')
		return (0);
	stock = img->map[img->player_height][img->player_width];
	img->map[img->player_height][img->player_width] = img->map[img->player_height][img->player_width - 1];
	img->map[img->player_height][img->player_width - 1] = stock;
	if (img->map[img->player_height][img->player_width] == 'C')
	{
		img->map[img->player_height][img->player_width] = '0';
		coin_collect(img);
		img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/link_left.xpm", &img->img_height, &img->img_height);
		mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, (img->player_width - 1) * 52, img->player_height * 52);
		return (0);
	}
	print_sprite(img, img->player_height, img->player_width);
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, img->player_width * 52, img->player_height * 52);
	img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/link_left.xpm", &img->img_height, &img->img_height);
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, (img->player_width - 1) * 52, img->player_height * 52);
	return (0);
}

static int player_up(t_data *img)
{
	char	stock;
	
	if (img->map[img->player_height - 1][img->player_width] == '1' || img->map[img->player_height - 1][img->player_width] == 'E')
		return (0);
	stock = img->map[img->player_height][img->player_width];
	img->map[img->player_height][img->player_width] = img->map[img->player_height - 1][img->player_width];
	img->map[img->player_height - 1][img->player_width] = stock;
	if (img->map[img->player_height][img->player_width] == 'C')
	{
		img->map[img->player_height][img->player_width] = '0';
		coin_collect(img);
		img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/link_back.xpm", &img->img_height, &img->img_height);
		mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, img->player_width * 52, (img->player_height - 1) * 52);
		return (0);
	}
	print_sprite(img, img->player_height, img->player_width);
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, img->player_width * 52, img->player_height * 52);
	img->sprite = mlx_xpm_file_to_image(img->mlx, "./asset/sprites/link_back.xpm", &img->img_height, &img->img_height);
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->sprite, img->player_width * 52, (img->player_height - 1) * 52);
	return (0);
}

void	exit_window(int keycode, t_data *img)
{
	if (keycode == 2)
	{
		if (img->map[img->player_height][img->player_width + 1] == 'E')
			destroy_game(img);
	}
	else if (keycode == 1)
	{
		if (img->map[img->player_height + 1][img->player_width] == 'E')
			destroy_game(img);
	}
	if (keycode == 0)
	{
		if (img->map[img->player_height][img->player_width - 1] == 'E')
			destroy_game(img);
	}
	if (keycode == 13)
	{
		if (img->map[img->player_height - 1][img->player_width] == 'E')
			destroy_game(img);
	}
}

void	monster_encounter(int keycode, t_data *img)
{
	if (keycode == 2)
	{
		if (img->map[img->player_height][img->player_width + 1] == 'M')
			destroy_game(img);
	}
	else if (keycode == 1)
	{
		if (img->map[img->player_height + 1][img->player_width] == 'M')
			destroy_game(img);
	}
	if (keycode == 0)
	{
		if (img->map[img->player_height][img->player_width - 1] == 'M')
			destroy_game(img);
	}
	if (keycode == 13)
	{
		if (img->map[img->player_height - 1][img->player_width] == 'M')
			destroy_game(img);
	}
}

int	player_movement(int keycode, t_data *img)
{	
	img->player_height = 0;
	img->player_width = 0;
	find_player(img);
	monster_encounter(keycode, img);
	if (img->coins == 0)
	{
		new_exit(img);
		exit_window(keycode, img);
	}
	if (img->mlx != NULL && keycode == 2)
		player_right(img);
	else if (img->mlx != NULL && keycode == 1)
		player_down(img);
	else if (img->mlx != NULL && keycode == 0)
		player_left(img);
	else if (img->mlx != NULL && keycode == 13)
		player_up(img);
	img->move_count++;
	ft_printf("Move count: %d\n", img->move_count);
	return (0);
}