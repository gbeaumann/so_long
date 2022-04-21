/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:02:45 by gbeauman          #+#    #+#             */
/*   Updated: 2021/11/25 11:05:26 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"ft_printf.h"

int	ft_check(char check, va_list argptr, int index)
{
	if (check == 's')
		index = ft_print_s(va_arg(argptr, char *), index);
	else if (check == 'c')
		index = ft_print_c(va_arg(argptr, int), index);
	else if (check == 'd' || check == 'i')
		index = ft_putnbr(va_arg(argptr, int), index);
	else if (check == 'u')
		index = ft_putnbr_u(va_arg(argptr, unsigned int), index);
	else if (check == 'x')
		index = ft_putnbr_x(va_arg(argptr, unsigned int), index);
	else if (check == 'X')
		index = ft_putnbr_mx(va_arg(argptr, unsigned int), index);
	else if (check == 'p')
		index = ft_print_p(va_arg(argptr, unsigned long ), index);
	else if (check == '%')
	{
		write (1, "%", 1);
		index++;
	}
	return (index);
}
