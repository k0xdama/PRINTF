/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:38 by pmateo            #+#    #+#             */
/*   Updated: 2023/09/10 19:29:41 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int     conv_specifiers(const char *str, va_list args, t_flags *flags, int *i)
{
	int	printed;
	
	printed = 0;
	if (str[(*i)] == 'c')
		printed += ft_printchar(va_arg(args, int), flags);
	else if (str[(*i)] == 's')
		printed += ft_printstr(va_arg(args, char *), flags);
	else if (str[(*i)] == 'p')
		printed += ft_printptr(va_arg(args, uintptr_t), flags);
	else if (str[(*i)] == 'd' || str[(*i)] == 'i')
		printed += ft_printnbr(va_arg(args, int), flags);
	else if (str[(*i)] == 'u')
		printed += ft_printunbr(va_arg(args, unsigned int), flags);
	else if (str[(*i)] == 'x' || str[(*i)] == 'X')
		printed += ft_printhexa(va_arg(args, unsigned long int), flags, str[(*i)]);
	else if (str[(*i)] == '%')
		printed += ft_printchar('%', flags);
	return (printed);
}

void	pathfinder2(const char *str, t_flags *flags, int *i)
{
	if (str[(*i)] == '0')
		flags->zero = 1;
	flags->width_field = ft_atoi(str, i);
	if (str[(*i)] == '.')
	{
		flags->dot = 1;
		(*i)++;
	}
	flags->dot_field = ft_atoi(str, i);
}

int	pathfinder1(const char *str, va_list args, t_flags *flags, int *i)
{
	int printed;

	printed = 0;
	(*i)++;
	if (str[(*i)] == '-' || str[(*i)+1] == '-' || str[(*i)+2] == '-'
		|| str[(*i)+2] == '-')
		flags->dash = 1;
	if (str[(*i)] == '+' || str[(*i)+1] == '+' || str[(*i)+2] == '+'
		|| str[(*i)+3] == '+')
		flags->plus = 1;
	if (str[(*i)] == ' ' || str[(*i)+1] == ' ' || str[(*i+2)] == ' '
		|| str[(*i)+3] ==  ' ')
		flags->space = 1;
	if (str[(*i)] == '#' || str[(*i)+1] == '#' || str[(*i+2)] == '#'
		|| str[(*i)+3] ==  '#')
		flags->htag = 2;
	while (str[(*i)] == '+' || str[(*i)] == '-' || str[(*i)] == ' '
		|| str[(*i)] == '#')
		(*i)++;
	pathfinder2(str, flags, i);
	printed += conv_specifiers(str, args, flags, i);
	(*i)++;
	return (printed);
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
    int ret = 0;
	// char *str = "ntm";
    ret = ft_printf("%+ #12X", 42);
	printf("\n");
	printf("%d", ret);
}
