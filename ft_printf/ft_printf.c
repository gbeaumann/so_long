/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:09:26 by gbeauman          #+#    #+#             */
/*   Updated: 2021/11/24 10:06:38 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		i;
	int		index;

	i = 0;
	index = 0;
	va_start(argptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			index = ft_check(str[i], argptr, index);
		}
		else
		{
			write (1, &str[i], 1);
			index++;
		}
		i++;
	}
	va_end(argptr);
	return (index);
}
