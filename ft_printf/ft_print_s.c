/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 09:54:14 by gbeauman          #+#    #+#             */
/*   Updated: 2021/11/25 11:28:19 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"ft_printf.h"

int	ft_print_s(char *s, int index)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		index = index + 6;
		return (index);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
		index++;
	}
	return (index);
}
