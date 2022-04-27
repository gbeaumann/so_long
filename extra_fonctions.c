/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:45:34 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/27 14:06:50 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	count_coins(char *gnl_map)
{
	int	index;
	int	coins;

	index = 0;
	coins = 0;
	while (gnl_map[index])
	{
		if (gnl_map[index] == 'C')
			coins++;
		index++;
	}
	return (coins);
}

void	destroy_game(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_window);
	exit(0);
}