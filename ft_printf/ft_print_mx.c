/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:56:57 by gbeauman          #+#    #+#             */
/*   Updated: 2021/11/25 11:06:11 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"ft_printf.h"

int	ft_print_mx(unsigned int num, int index)
{
	char			*list;
	int				i;
	unsigned int	check;

	list = "ABCDEF";
	i = 0;
	check = 10;
	while (check != num)
	{
		i++;
		check++;
	}
	write (1, &list[i], 1);
	index++;
	return (index);
}
