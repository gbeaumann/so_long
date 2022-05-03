/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:51:01 by gbeauman          #+#    #+#             */
/*   Updated: 2022/05/03 14:40:52 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

static int	init_read(int fd, t_read_map *gnl)
{
	gnl->fd = fd;
	gnl->pos = 0;
	gnl->max = read(fd, gnl->backup, BUFFER_SIZE);
	if (gnl->max <= 0)
		return (0);
	else
		return (1);
}

static char	check_read(t_read_map *gnl)
{
	char	resultat;

	if (gnl->pos >= gnl->max)
	{
		gnl->pos = 0;
		gnl->max = read(gnl->fd, gnl->backup, BUFFER_SIZE);
		if (gnl->max <= 0)
			return (0);
	}
	resultat = gnl->backup[gnl->pos];
	gnl->pos++;
	return (resultat);
}

static int	ft_len(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
		index++;
	return (index);
}

static char	*ft_join(char *str, char ch)
{
	char	*new_str;
	int		index;
	int		len;

	index = 0;
	len = ft_len(str);
	new_str = malloc((len + 2) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (index < len)
	{
		new_str[index] = str[index];
		index++;
	}
	new_str[index] = ch;
	new_str[index + 1] = '\0';
	if (str)
		free(str);
	return (new_str);
}

char	*get_next_line(int fd, t_read_map *gnl, t_data *img)
{
	char	ch;
	char	*str;
	int		index;
	int		height;

	index = 0;
	height = 0;
	str = NULL;
	if (gnl->fd != fd)
	{
		if (!init_read(fd, gnl))
			map_empty();
	}
	ch = check_read(gnl);
	while (ch)
	{
		if (ch == '\n')
			height++;
		str = ft_join(str, ch);
		ch = check_read(gnl);
	}
	dimention_finder(str, img);
	return (str);
}
