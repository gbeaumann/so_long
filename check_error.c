/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:17:27 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/27 14:27:04 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

static void	error_size(int length, int width)
{
	if (length != width)
	{
		ft_printf("Error, wrong map size");
		exit (0);
	}
}

static void	check_map_size(t_data *img, char *map_gnl)
{
	int	index;
	int	width;
	int	length;

	index = 0;
	length = 0;
	while (map_gnl[index] != '\n')
		index++;
	width = index;
	index++;
	while (map_gnl[index])
	{
		if (map_gnl[index] == '\n')
		{
			error_size(length, width);
			index++;
			length = 0;
		}
		index++;
		length++;
	}
	error_size (length, width);
}

static void	error_walls(void)
{
	ft_printf ("Error, hole in the wall");
	exit (0);
}

static void	check_walls(t_data *img)
{
	int	ht;
	int	len;

	ht = 0;
	len = 0;
	while (img->map[ht][len])
	{
		if (img->map[ht][len] != '1')
			error_walls();
		len++;
	}
	ht++;
	while (ht < img->height - 1)
	{
		if (img->map[ht][0] != '1' || img->map[ht][img->width - 1] != '1')
			error_walls();
		ht++;
	}
	len = 0;
	while (img->map[ht][len])
	{
		if (img->map[ht][len] != '1')
			error_walls();
		len++;
	}
}

void	check_error(t_data *img, t_read_map *gnl, char *map_gnl)
{
	check_map_size(img, map_gnl);
	check_walls(img);
	check_player(map_gnl);
	check_exit(map_gnl);
	check_coin(map_gnl);
}
