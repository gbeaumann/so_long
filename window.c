/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:34:35 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/20 14:38:14 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int ft_clic_close(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_window);
	exit (0);
}

int	ft_close(int keycode, t_data *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_window);
		exit(0);
	}
	return (0);
}