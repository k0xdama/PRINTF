/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:43 by pmateo            #+#    #+#             */
/*   Updated: 2023/09/10 18:06:34 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

static int ft_puthexa(unsigned int nbr, int bool)
{
    int len;
    unsigned long nbl;
    char *basemaj;
    char *basemin;

    len = ft_nbrlen(nbr, 16);
    nbl = nbr;
    basemaj = "0123456789ABCDEF";
    basemin = "0123456789abcdef";
    if (nbl <= 16 && bool == 0)
        ft_putchar_with_ret(basemin[nbl]);
    else if (nbl <= 16 && bool == 1)
        ft_putchar_with_ret(basemaj[nbl]);
    if (nbl > 16)
    {
        ft_puthexa(nbl / 16, bool);
        ft_puthexa(nbl % 16, bool);
    }
    return (len);
}

static int	dash_on(unsigned int nbr, t_flags *flags, int *precision, int *width_size)
{
	int	printed;

	printed = 0;
	if (flags->htag == 2)
	{
		if (flags->hex_cap == 1)
			printed += ft_putstr("0X", 2);
		else
			printed += ft_putstr("0x", 2);
	}
	while ((*precision)-- > 0)
		printed += ft_putchar_with_ret('0');
	if (flags->hex_cap == 1)
		printed += ft_puthexa(nbr, 1);
	else
		printed += ft_puthexa(nbr, 0);
	while ((*width_size)-- > 0)
		printed += ft_putchar_with_ret(' ');
	return (printed);
}

static int	dash_off(unsigned int nbr, t_flags *flags, int *precision, int *width_size)
{
	int	printed;

	printed = 0;
	while (((*width_size)-- > 0) && (flags->zero == 1))
		printed += ft_putchar_with_ret('0');
	while (((*width_size)-- > 0) && (flags->zero == 0))
		printed += ft_putchar_with_ret(' ');
	if (flags->htag == 2)
	{
		if (flags->hex_cap == 1)
			printed += ft_putstr("0X", 2);
		else
			printed += ft_putstr("0x", 2);
	}
	while ((*precision)-- > 0)
		printed += ft_putchar_with_ret('0');
	if (flags->hex_cap == 1)
		printed += ft_puthexa(nbr, 1);
	else
		printed += ft_puthexa(nbr, 0);
	return (printed);
}

int	ft_printhexa(unsigned int nbr, t_flags *flags, char format)
{
	int	printed;
	int	nbrlen;
	int	precision;
	int	width_size;

	printed = 0;
	nbrlen = ft_nbrlen(nbr, 16);
	precision = flags->dot_field;
	if (flags->dot == 1 && nbrlen < precision)
		precision -= nbrlen;
	width_size = flags->width_field - (nbrlen + precision + flags->htag);
	if (format == 'X')
		flags->hex_cap = 1;
	if (flags->dash == 1)
		printed += dash_on(nbr, flags, &precision, &width_size);
	else if (flags->dash == 0)
		printed += dash_off(nbr, flags, &precision, &width_size);
	return (printed);
}