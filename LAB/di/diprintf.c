/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:18:15 by pmateo            #+#    #+#             */
/*   Updated: 2023/09/02 04:35:54 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct s_flags
{
    int     width_field;
    int     dot_field;
    int     dot;
    int     zero;
    int     tsix;
    int     space;
    int     plus;
}   t_flags;

void    up_struct(t_flags *flags)
{
    flags->width_field = 0;
    flags->dot_field = 0;
    flags->dot = 0;
    flags->zero = 0;
    flags->tsix = 0;
    flags->space = 0;
    flags->plus = 0;
}

int ft_putchar_with_ret(char c)
{
    return(write(1, &c, 1));
}

int ft_nbrlen(int nbr)
{
    int i;

    i = 0;
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
	while (str[(*i)] >= '0' && str[(*i)] <= '9')
	{
		num = num * 10 + (str[(*i)] - 48);
		(*i)++;
	}
	return (num);
}

int	ft_putnbr(int nbr)
{
	long	nbl;
    int     len;
    
    len = ft_nbrlen(nbr);
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

int	print_width_and_put(int nbr, t_flags *flags, int *precision, int *width_size)
{
	int printed;

	printed = 0;
	if (flags->tsix == 1)
	{
		if (flags->plus == 1)
			printed += ft_putchar_with_ret('+');
		while ((*precision)-- != 0)
			printed += ft_putchar_with_ret('0');
		printed += ft_putnbr(nbr);
		while ((*width_size)-- != 0)
			printed += ft_putchar_with_ret(' ');
	}
	else
	{
		if (flags->plus == 1)
			printed += ft_putchar_with_ret('+');
		if (flags->zero == 1 && flags->dot == 0)
		{
			while ((*width_size)-- != 0)
				printed += ft_putchar_with_ret('0');
		}
		else
		{
			while ((*width_size)-- != 0)
				printed += ft_putchar_with_ret(' ');
		}
		while ((*precision)-- != 0)
			printed += ft_putchar_with_ret('0');
		printed += ft_putnbr(nbr);
	}
	return (printed);
}

int printnbr(int nbr, t_flags *flags)
{
    int printed;
	int nbrlen;
	int precision;
	int width_size;

    printed = 0;
	nbrlen = ft_nbrlen(nbr);
	precision = flags->dot_field;
	if (flags->dot == 1 && precision > nbrlen)
		precision -= nbrlen;
	width_size = flags->width_field - (nbrlen + precision + flags->plus + flags->space);
	if (flags->space == 1)
		printed += ft_putchar_with_ret(' ');
	printed += print_width_and_put(nbr, flags, &precision, &width_size);
	return (printed);
}

int pathfinder(const char *str, va_list args, t_flags *flags, int *i)
{
    int printed;

    printed = 0;
    (*i)++;
    if (str[(*i)] == '-' || str[(*i)+1] == '-' || str[(*i)+2] == '-')
        flags->tsix = 1;
    if (str[(*i)] == '+' || str[(*i)+1] == '+' || str[(*i)+2] == '+')
        flags->plus = 1;
	if ((str[(*i)] == ' ' || str[(*i)+1] == ' ') && (flags->plus != 1))
		flags->space = 1;
    while (str[(*i)] == '+' || str[(*i)] == '-' || str[(*i)] == ' ')
		(*i)++;
    if (str[(*i)] == '0')
        flags->zero = 1;
    flags->width_field = ft_atoi(str, i);
    if (str[(*i)] == '.')
    {
        flags->dot = 1;
		(*i)++;
        flags->dot_field = ft_atoi(str, i);
    }
    printed += printnbr(va_arg(args, int), flags);
	(*i)++;
    return (printed);
}

int ft_diprintf(const char *str, ...)
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
            printed += pathfinder(str, args, &flags, &i);
        else
		{
            printed += ft_putchar_with_ret(str[i]);
        	i++;
		}
    }
    va_end(args);
    return(printed);
}

int main(void)
{
    int ret = 0;
	int nbr = 42;
	ret = ft_diprintf("%- 07d", nbr);
	printf("\n");
	printf("ret = %d\n", ret);
}

