/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:39:53 by pmateo            #+#    #+#             */
/*   Updated: 2023/08/23 23:40:37 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef	struct s_flags
{
	int			width_field;
	int			tsix;
}	t_flags;

void	up_struct(t_flags *flags)
{
	flags->width_field = 0;
	flags->tsix = 0;
}

int	ft_putchar_with_ret(char c)
{
	return(write(1, &c, 1));
}

int	ft_atoi(const char *str)
{
	int	num;
	
	num = 0;
	while ((*str <= '0' || *str >= '9') && (*str))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - 48);
		str++;
	}
	return (num);
}

int	printchar(char c, t_flags *flags)
{
	int printed;
	int	width_size;

	printed = 0;
	width_size = 0;
	if (flags->width_field != 0)
	{
		width_size = flags->width_field;
		if (flags->tsix == 1)
			printed += ft_putchar_with_ret(c);
		while (width_size != 1)
		{
			printed += ft_putchar_with_ret(' ');
			width_size--;
		}
		if (flags->tsix == 0)
			printed += ft_putchar_with_ret(c);
	}
	else
		printed += ft_putchar_with_ret(c);
	return (printed);
}

int	pathfinder(const char *str, va_list args, t_flags *flags, int *i)
{
	int printed;

	printed = 0;
	(*i)++;
	if (str[(*i)] == '-')
	{
		flags->tsix = 1;
		(*i)++;
	}
	flags->width_field = ft_atoi(str);
	while (str[(*i)] >= '0' && str[(*i)] <= '9')
		(*i)++;
	printed += printchar(va_arg(args, int), flags);
	(*i)++;
	return (printed);
}

int	ft_cprintf(const char *str, ...)
{
	int	printed;
	int i;
	va_list	args;
	t_flags flags;
	
	printed = 0;
	i = 0;
	va_start(args, str);
	up_struct(&flags);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printed += pathfinder(str+i, args, &flags, &i);
		}
		else
		{
			printed += ft_putchar_with_ret(*str);
			i++;
		}
	}
	va_end(args);
	return (printed);
}

int	main(void)
{
	int result;
	char c = 'v';
	result = ft_cprintf("%-5c", c);
	printf("\nresult : %d\n", result);
}