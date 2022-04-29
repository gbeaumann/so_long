/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:15:52 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/28 11:20:59 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	check_player(char *map_gnl)
{
	int	index;
	int	check_p;
	
	index = 0;
	check_p = 0;
	while (map_gnl[index])
	{
		if (map_gnl[index] == 'P')
			check_p++;
		index++;
	}
	if (check_p == 0 || check_p > 1)
	{
		ft_printf ("Error, wrong number of player");
		exit (0);
	}
}

void	check_exit(char *map_gnl)
{
	int	index;
	int	check_e;

	index = 0;
	check_e = 0;
	while (map_gnl[index])
	{
		if (map_gnl[index] == 'E')
			check_e++;
		index++;
	}
	if (check_e < 1)
	{
		ft_printf ("Error, no exit");
		exit (0);
	}
}

void	check_coin(char *map_gnl)
{
	int	index;
	int	check_c;
	
	index = 0;
	check_c = 0;
	while (map_gnl[index])
	{
		if (map_gnl[index] == 'C')
			check_c++;
		index++;
	}
	if (check_c == 0)
	{
		ft_printf ("Error, no ruby on the map");
		exit (0);
	}
}

void	check_arguments(void)
{
	ft_printf ("Error, wrong number of arguments");
	exit (0);
}
