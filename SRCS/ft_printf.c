/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:38 by pmateo            #+#    #+#             */
/*   Updated: 2023/08/27 18:27:01 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include "../INCLUDES/ft_printf.h"

void	flags_specifiers(const char *str, t_flags *flags)
{
	if (is_flags(*str, "0-+ #"))
	{
		if (*str == '0')
			flags->zero = 1;
		else if (*str == '-')
			flags->tsix = 1;
		else if (*str == '+')
			flags->plus = 1;
		else if (*str == ' ')
			flags->space = 1;
		else if (*str == '#')
			flags->htag = 1;
		if (*str+1 >= 1 && *str+1 <= 9)
			flags->width_field = ft_atoi(str+1);
	}
	else if (*str == '.')
	{
		flags->dot = 1;
		flags->dot_field = ft_atoi(str+1);
	}	
}


int     conv_specifiers(const char *str, t_flags *flags, va_list args)
{
	int	printed;
	
	printed = 0;
	if (*str == 'c')
		printed += ft_printchar(va_arg(args, char), flags);
	else if (*str == 's')
		printed += ft_printstr(va_arg(args, char *), flags);
	else if (*str == 'p')
		printed += ft_printptr(va_arg(args, void *), flags);
	else if (*str == 'd' || *str == 'i')
		printed += ft_printnbr(va_arg(args, int), flags);
	else if (*str == 'u')
		printed += ft_printunbr(va_arg(args, int), flags);
	else if (*str == 'x' || *str == 'X')
		printed += ft_printhexa(va_arg(args, int), flags);
	else if (*str == '%')
		printed += ft_printchar('%', flags);	
	return (printed);
}

int	pathfinder(const char *str, int *i, va_list args)
{
	int	printed;
	t_flags *flags;
	
	printed = 0;
	up_struct(&flags);
	(*i)++;
	if (is_flags(str[(*i)], "123456789"))
		flags->width_field += ft_atoi(str+(*i));
	while (is_flags(str[(*i)], "0-.# +"))
	{
		flags_specifiers(str+(*i), &flags);
		(*i)++;
	}
	printed += conv_specifiers(str+(*i), &flags, args);
	return (printed);
}


int ft_printf(const char *str, ...)
{
	size_t  i;
	int	printed;
	va_list args;

	i = 0;
	printed = 0;
	va_start(args, str);
	while(str[i])
	{
		if(str[i] == '%')
		{
			printed += pathfinder(str, &i, args);
		}
		else
			printed += ft_putchar_with_ret(str[i]);
		i++;
	}
	va_end(args);
	return (printed);
}


int main(void)
{
    int nb = 42;
    ft_printf("blabla = %d", 42);
}
