/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:39:31 by gbeauman          #+#    #+#             */
/*   Updated: 2022/05/03 11:39:14 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	map_empty(void)
{
	ft_printf ("Error, the map is empty\n");
	exit (0);
}

void	check_map_composition(char *map_gnl)
{
	int	i;

	i = 0;
	while (map_gnl[i])
	{
		if (map_gnl[i] == '1' || map_gnl[i] == '0' || map_gnl[i] == 'P'
			|| map_gnl[i] == 'M' || map_gnl[i] == 'C'
			|| map_gnl[i] == 'E' || map_gnl[i] == '\n')
			i++;
		else
		{
			ft_printf ("Error, unkown map composition\n");
			exit (0);
		}
	}
}

void	check_map_existance(void)
{
	ft_printf ("Error, this map doesn't exist\n");
	exit (0);
}
