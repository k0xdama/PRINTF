/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xXprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 00:18:46 by u4s2e0r           #+#    #+#             */
/*   Updated: 2023/09/06 04:59:48 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct s_flags
{
    int     width_field;
    int     dot_field;
    int     dot;
    int     zero;
    int     tsix;
    int     htag;
}   t_flags;

void    up_struct(t_flags *flags)
{
    flags->width_field = 0;
    flags->dot_field = 0;
    flags->dot = 0;
    flags->zero = 0;
    flags->tsix = 0;
    flags->htag = 0;
}

int ft_putchar_with_ret(char c)
{
    return (write(1, &c, 1));
}

int ft_putstr(const char *str)
{
    int i;

    i = 0;
    while (str[i])
	{
        write(1, &str[i], 1);
		i++;
	}
    return (i);
}

int ft_hexlen(unsigned int nbr)
{
    int i;

    i = 0;
    if (nbr == 0)
        i = 1;
    while (nbr != 0)
    {
        nbr /= 16;
        i++;
    }
    return (i);
}

int	ft_atoi(const char *str, int *i)
{
	int	num;
	
	num = 0;
	while (str[(*i)] >= '0' && str[(*i)] <= '9')
	{
		num = num * 10 + (str[(*i)] - 48);
		(*i)++;
	}
	return (num);
}

int ft_puthex(unsigned int nbr, int bool)
{
    int len;
    unsigned long nbl;
    char *basemaj;
    char *basemin;

    len = ft_hexlen(nbr);
    nbl = nbr;
    basemaj = "0123456789ABCDEF";
    basemin = "0123456789abcdef";
    if (nbl <= 16 && bool == 0)
        ft_putchar_with_ret(basemin[nbl]);
    else if (nbl <= 16 && bool == 1)
        ft_putchar_with_ret(basemaj[nbl]);
    if (nbl > 16)
    {
        ft_puthex(nbl / 16, bool);
        ft_puthex(nbl % 16, bool);
    }
    return (len);
}

int print_width_and_nbr(unsigned int nbr, t_flags *flags, int *precision, int *width_size)
{
    int printed;

    printed = 0;
    if (flags->tsix == 1)
    {
        if (flags->htag == 2)
            printed += ft_putstr("0x");
		while ((*precision)-- > 0 && flags->dot == 1)
			printed += ft_putchar_with_ret('0');
        printed += ft_puthex(nbr, 0);
        while ((*width_size)-- > 0)
            printed += ft_putchar_with_ret(' ');
    }
    else
    {
        if (flags->htag == 2)
            printed += ft_putstr("0x");
		if (flags->zero == 1 && flags->dot == 0)
        {
            while ((*width_size)-- > 0)
                printed += ft_putchar_with_ret('0');
        }
        else
        {
            while ((*width_size)-- > 0)
                printed += ft_putchar_with_ret(' ');
        }
        while ((*precision)-- > 0 && flags->dot == 1)
            printed += ft_putchar_with_ret('0');
        printed += ft_puthex(nbr, 0);
    }
    return (printed);
}

int printhex(unsigned int nbr, t_flags *flags)
{
    int printed;
    int nbrlen;
    int precision;
    int width_size;

    printed = 0;
    nbrlen = ft_hexlen(nbr);
    precision = flags->dot_field;
    if (flags->dot == 1 && (nbrlen < precision))
        precision -= nbrlen;
    width_size = flags->width_field - (nbrlen + precision + flags->htag);
    printed += print_width_and_nbr(nbr, flags, &precision, &width_size);
    return (printed);
}

int pathfinder(const char *str, t_flags *flags, va_list args, int *i)
{
    int printed;

    printed = 0;
    (*i)++;
    if (str[(*i)] == '-' || str[(*i)+1] == '-' || str[(*i)+2] == '-' || str[(*i)+3] == '-')
        flags->tsix = 1;
    if (str[(*i)] == '#' || str[(*i)+1] == '#' || str[(*i)+2] == '#' || str[(*i)+3] == '#')
        flags->htag = 2;
    while (str[(*i)] == '-' || str[(*i)] == '#' || str[(*i)] == ' ' || str[(*i)] == '+')
        (*i)++;
    if (str[(*i)] == '0')
        flags->zero = 1;
    flags->width_field = ft_atoi(str, i);
    while (str[(*i)] >= 0 && str[(*i)] <= 9)
        (*i)++;
    if (str[(*i)] == '.')
    {
        flags->dot = 1;
        (*i)++;
    }
    flags->dot_field = ft_atoi(str, i);
    while (str[(*i)] >= 0 && str[(*i)] <= 9)
        (*i)++;
    printed += printhex(va_arg(args, unsigned int), flags);
	(*i)++;
    return (printed);
}


int ft_xXprintf(const char *str, ...)
{
    int printed;
    int i;
    t_flags flags;
    va_list args;

    printed = 0;
    i = 0;
    up_struct(&flags);
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%')
            printed += pathfinder(str, &flags, args, &i);
        else
        {
            printed += ft_putchar_with_ret(str[i]);
            i++;
        }
    }
    va_end(args);
    return (printed);
}

int main(void)
{
    int ret = 0;
    ret = ft_xXprintf("%014xc%020xs%02xx%0xi", -1, 3, 30, -1);
    printf("\n");
    printf("%d", ret);
	printf("\n");
}