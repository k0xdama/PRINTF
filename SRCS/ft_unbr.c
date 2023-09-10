/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:40 by pmateo            #+#    #+#             */
/*   Updated: 2023/09/10 18:59:00 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

static int	ft_uputnbr(unsigned int nbr)
{
	unsigned long	nbl;
	int len;

	nbl = nbr;
	len = ft_nbrlen(nbr, 10);
	if (nbl <= 9)
		ft_putchar_with_ret(nbl + 48);
	if (nbl > 9)
	{
		ft_uputnbr(nbl / 10);
		ft_uputnbr(nbl % 10);
	}
	return (len);
}

static int	dash_on(unsigned int nbr, int *precision, int *width_size)
{
	int	printed;

	printed = 0;
	while ((*precision)-- >= 0)
		printed += ft_putchar_with_ret('0');
	printed += ft_uputnbr(nbr);
	while ((*width_size)-- >= 0)
		printed += ft_putchar_with_ret(' ');
	return (printed);
}

static int	dash_off(unsigned int nbr, t_flags *flags, int *precision, int *width_size)
{
	int	printed;

	printed = 0;
	if (flags->zero == 1)
	{
		while ((*width_size)-- >= 0)
			printed += ft_putchar_with_ret('0');
	}
	else
	{
		while ((*width_size)-- >= 0)
			printed += ft_putchar_with_ret(' ');
	}
	while ((*precision)-- >= 0)
		printed += ft_putchar_with_ret('0');
	printed += ft_uputnbr(nbr);
	return (printed);
}

int	ft_printunbr(unsigned int nbr, t_flags *flags)
{
	int	printed;
	int	nbrlen;
	int	precision;
	int	width_size;

	printed = 0;
	nbrlen = ft_nbrlen(nbr, 10);
	precision = flags->dot_field;
	if (flags->dot == 1 && nbrlen < precision)
		precision -= nbrlen;
	width_size = flags->width_field - (nbrlen + precision);
	if (flags->dash == 1)
		printed += dash_on(nbr, &precision, &width_size);
	else if (flags->dash == 0)
		printed += dash_off(nbr, flags, &precision, &width_size);
	return (printed); 
}


// int	main(void)
// {
// 	unsigned int nb = 4568001447;
// 	int ret1 = ft_uputnbr(nb);
// 	printf("\n");
// 	int ret2 = printf("%u", nb);
// 	printf("\n");
// 	printf("ret1 = %d\n", ret1);
// 	printf("ret2 = %d\n", ret2);
// }
