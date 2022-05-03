/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:15:52 by gbeauman          #+#    #+#             */
/*   Updated: 2022/05/03 11:35:17 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	check_player(char *map_gnl)
{
	int	i;
	int	check_p;

	i = 0;
	check_p = 0;
	while (map_gnl[i])
	{
		if (map_gnl[i] == 'P')
			check_p++;
		i++;
	}
	if (check_p == 0 || check_p > 1)
	{
		ft_printf ("Error, wrong number of player\n");
		exit (0);
	}
}

void	check_exit(char *map_gnl)
{
	int	i;
	int	check_e;

	i = 0;
	check_e = 0;
	while (map_gnl[i])
	{
		if (map_gnl[i] == 'E')
			check_e++;
		i++;
	}
	if (check_e < 1)
	{
		ft_printf ("Error, no exit\n");
		exit (0);
	}
}

void	check_coin(char *map_gnl)
{
	int	i;
	int	check_c;

	i = 0;
	check_c = 0;
	while (map_gnl[i])
	{
		if (map_gnl[i] == 'C')
			check_c++;
		i++;
	}
	if (check_c == 0)
	{
		ft_printf ("Error, no ruby on the map\n");
		exit (0);
	}
}

void	check_arguments(void)
{
	ft_printf ("Error, wrong number of arguments\n");
	exit (0);
}

int	check_map_name(char *name)
{
	int	i;

	i = ft_strlen(name);
	if (name[i - 1] != 'r' && name[i - 2] != 'e'
		&& name[i - 3] != 'b' && name[i - 4] != '.')
	{
		ft_printf ("Error, wrong map name\n");
		exit(0);
	}
	return (0);
}
