/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:49:52 by gbeauman          #+#    #+#             */
/*   Updated: 2021/11/25 11:21:29 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"ft_printf.h"

int	ft_print_p(unsigned long str, int index)
{
	unsigned long	*add;
	unsigned long	**ptr;

	add = &str;
	ptr = &add;
	write (1, "0x", 2);
	index = index + 2;
	index = ft_putnbr_p(**ptr, index);
	return (index);
}
