/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:41:04 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/21 11:14:02 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

static char 	*map_filling(char *map_gnl, t_read_map *gnl)
{
	char			*line;
	static int		index_gnl = 0;
	int				index;

	index = 0;
	line = malloc(gnl->width * sizeof(char));
	if (!line)
		return (NULL);
	while (map_gnl[index_gnl])
	{
		if (map_gnl[index_gnl] == '\n')
		{
			index_gnl++;
			line[index] = '\0';
			return (line);
		}
		line[index] = map_gnl[index_gnl];
		index++;
		index_gnl++;
	}
	line[index] = '\0';
	//ft_printf("test :%c\n", line[0]);
	return (line);
}
char	**get_map(t_read_map *gnl, t_data *img, char *map_gnl)
{
	int	index_heigth;

	//printf("%s\n", map_gnl);
	//printf("\n");
	index_heigth = 0;
	img->map = malloc(gnl->height * sizeof(char));
	if (!img->map)
		return (NULL);
	while (index_heigth <= gnl->height)
	{
		img->map[index_heigth] = map_filling(map_gnl, gnl);
		//ft_printf("%c\n", img->map[index_heigth][0]);
		index_heigth++;
	}
	//ft_printf("%c\n", &img->map[0][0]);
	return (img->map);
}
