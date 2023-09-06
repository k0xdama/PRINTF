/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:20 by pmateo            #+#    #+#             */
/*   Updated: 2023/09/06 05:00:21 by pmateo           ###   ########.fr       */
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
}   t_flags;

void    up_struct(t_flags *flags)
{
    flags->width_field = 0;
    flags->dot_field = 0;
    flags->dot = 0;
    flags->zero = 0;
    flags->tsix = 0;
}

int ft_putchar_with_ret(char c)
{
    return(write(1, &c, 1));
}

int ft_nbrlen(int nbr)
{
    int i;

    i = 0;
	if (nbr == 0)
		i = 1;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str, int *i)
{
	int	num;
	
	num = 0;
    while (str[(*i)] < '0' || str[(*i)] > '9')
        (*i)++;
	while (str[(*i)] >= '0' && str[(*i)] <= '9')
	{
		num = num * 10 + (str[(*i)] - 48);
		(*i)++;
	}
	return (num);
}

int	ft_uputnbr(unsigned int nbr)
{
	unsigned long	nbl;
    int     len;
    
    len = ft_nbrlen(nbr);
	nbl = nbr;
    if (nbr < 0)
        return (0);
	if (nbl >= 0 && nbl <= 9)
		ft_putchar_with_ret(nbl + 48);
	if (nbl > 9)
	{
		ft_uputnbr(nbl / 10);
		ft_uputnbr(nbl % 10);
	}
    return (len);
}

int print_width_and_nbr(unsigned int nbr, t_flags *flags, int *precision, int *width_size)
{
    int printed;

    printed = 0;
    if (flags->tsix == 1)
	{
		while ((*precision)-- > 0)
			printed += ft_putchar_with_ret('0');
		printed += ft_uputnbr(nbr);
		while ((*width_size)-- > 0)
			printed += ft_putchar_with_ret(' ');
	}
    else
    {
        if (flags->zero == 1)
		{
			while ((*width_size)-- > 0)
				printed += ft_putchar_with_ret('0');
		}
		else
		{
			while ((*width_size)-- > 0)
				printed += ft_putchar_with_ret(' ');
		}
        while ((*precision)-- > 0)
			printed += ft_putchar_with_ret('0');
		printed += ft_uputnbr(nbr);
    }
    return (printed);
}

int printunbr(unsigned int nbr, t_flags *flags)
{
    int printed;
    int nbrlen;
    int precision;
    int width_size;

    printed = 0;
    nbrlen = ft_nbrlen(nbr);
    precision = flags->dot_field;
    if (flags->dot == 1 && nbrlen < precision)
        precision -= nbrlen;
    width_size = flags->width_field - (nbrlen + precision);
    printed += print_width_and_nbr(nbr, flags, &precision, &width_size);
    return (printed);
}

int pathfinder(const char *str, t_flags *flags, va_list args, int *i)
{
    int printed;

    printed = 0;
    (*i)++;
    if (str[(*i)] == '-' || str[(*i)+1] == '-' | str[(*i)+2] == '-')
        flags->tsix = 1;
    while (str[(*i)] == '+' || str[(*i)] == '-' || str[(*i)] == ' ')
		(*i)++;
    if (str[(*i)] == '0')
        flags->zero = 1;
    flags->width_field = ft_atoi(str, i);
    while (str[(*i)] >= '0' && str[(*i)] <= '9')
		(*i)++;
    if (str[(*i)] == '.')
    {
        flags->dot = 1;
        flags->dot_field = ft_atoi(str, i);
        while (str[(*i)] >= '0' && str[(*i)] <= '9')
			(*i)++;
    }
    if ((flags->zero == 1) && (flags->tsix == 1 || flags->dot == 1))
        flags->zero = 0;
    printed += printunbr(va_arg(args, unsigned int), flags);
    (*i)++;
    return (printed);
}

int ft_uprintf(const char *str, ...)
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
            printed += pathfinder(str+i, &flags, args, &i);
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
    int nb = 42;
    ret = ft_uprintf("%-8.3u", nb);
    printf("\n");
    printf("ret = %d", ret);
}