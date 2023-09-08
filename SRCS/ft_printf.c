/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:38 by pmateo            #+#    #+#             */
/*   Updated: 2023/09/08 22:14:12 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include "../INCLUDES/ft_printf.h"

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

int	pathfinder1(const char str, va_list args, t_flags *flags, int *i)
{
	int printed;

	printed = 0;
	(*i)++;
	if (str[(*i)] == '-' || str[(*i)+1] == '-' || str[(*i)+2] == '-'
		|| str[(*i)+2] == '-')
		flags->tsix = 1;
	if (str[(*i)] == '+' || str[(*i)+1] == '+' || str[(*i)+2] == '+'
		|| str[(*i)+3] == '+')
		flags->plus = 1;
	if (str[(*i)] == ' ' || str[(*i)+1] == ' ' || str[(*i+2)] == ' '
		|| str[(*i)+3] ==  ' ')
		flags->space == 1;
	if (str[(*i)] == '#' || str[(*i)+1] == '#' || str[(*i+2)] == '#'
		|| str[(*i)+3] ==  '#')
		flags->htag == 2;
	while (str[(*i)] == '+' || str[(*i)] == '-' || str[(*i)] == ' '
		|| str[(*i)] == '#')
		(*i)++;
	pathfinder(str, args, flags, i);
	printed += conv_specifiers(str, args, flags);
	return (printed)
}

int ft_printf(const char *str, ...)
{
	int	i;
	int	printed;
	t_flags flags;
	va_list args;

	i = 0;
	printed = 0;
	up_struct(&flags);
	va_start(args, str);
	while(str[i])
	{
		if(str[i] == '%')
			printed += pathfinder1(str, args, &flags, &i);
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
    int nb = 42;
    ft_printf("blabla = %d", 42);
}
