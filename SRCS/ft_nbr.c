/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:36:05 by pmateo            #+#    #+#             */
/*   Updated: 2023/09/11 17:11:02 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

static int	ft_putnbr(int nbr)
{
	long	nbl;
    int     len;
    
    len = ft_nbrlen(nbr, 10);
	nbl = nbr;
	if (nbl < 0)
	{
		write(1, "-", 1);
		nbl *= -1;
	}
	if (nbl >= 0 && nbl <= 9)
		ft_putchar_with_ret(nbl + 48);
	if (nbl > 9)
	{
		ft_putnbr(nbl / 10);
		ft_putnbr(nbl % 10);
	}
    return (len);
}

static int	dash_off(int nbr, t_flags *flags, int *precision, int *width_size)
{
	int	printed;
	int	printed_prec;

	printed = 0;
	printed_prec = 0;
	if (flags->zero == 1 && flags->dot != 1)
	{
		if (flags->plus == 1)
			printed += ft_putchar_with_ret('+');
		while (printed < (*width_size))
			printed += ft_putchar_with_ret('0');
	}
	else
	{
		while (printed < (*width_size))
			printed += ft_putchar_with_ret(' ');
	}
	if (flags->plus == 1)
		printed += ft_putchar_with_ret('+');
	while (printed_prec < (*precision))
		printed_prec += ft_putchar_with_ret('0');
	printed += ft_putnbr(nbr);
	return (printed + printed_prec);	
}

static int	dash_on(int nbr, t_flags *flags, int *precision, int *width_size)
{
	int	printed;
	int	printed_prec;

	printed = 0;
	printed_prec = 0;
	if (flags->plus == 1)
		printed += ft_putchar_with_ret('+');
	while (printed_prec < (*precision))
		printed_prec += ft_putchar_with_ret('0');
	printed += ft_putnbr(nbr);
	while (printed < (*width_size))
		printed += ft_putchar_with_ret(' ');
	return (printed + printed_prec);
}

int	ft_printnbr(int nbr, t_flags *flags)
{
	int	printed;
	int	nbrlen;
	int	precision;
	int	width_size;

	printed = 0;
	nbrlen = ft_nbrlen(nbr, 10);
	precision = flags->dot_field;
	if (flags->dot == 1 && precision > nbrlen)
		precision -= nbrlen;
	width_size = flags->width_field - (nbrlen + precision + flags->plus + flags->space);
	if (flags->space == 1)
		printed += ft_putchar_with_ret(' ');
	if (flags->dash == 1)
		printed += dash_on(nbr, flags, &precision, &width_size);
	else if (flags->dash == 0)
		printed += dash_off(nbr, flags, &precision, &width_size);
	return (printed);
}