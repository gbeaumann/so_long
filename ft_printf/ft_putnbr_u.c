/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:59:16 by gbeauman          #+#    #+#             */
/*   Updated: 2021/11/19 11:04:02 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"ft_printf.h"

int	ft_putnbr_u(unsigned int num, int index)
{
	if (num >= 0 && num <= 9)
		index = ft_print_u(num, index);
	else
	{
		index = ft_putnbr_u(num / 10, index + 1);
		ft_putnbr_u(num % 10, index);
	}
	return (index);
}
