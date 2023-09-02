/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:57:23 by pmateo            #+#    #+#             */
/*   Updated: 2023/09/02 19:47:21 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef	struct s_flags
{
	int			width_field;
	int			dot_field;
	int			tsix;
	int			dot;
}	t_flags;

void up_struct(t_flags *flags)
{
	flags->width_field = 0;
	flags->dot_field = 0;
	flags->tsix = 0;
	flags->dot = 0;
}

int	ft_putchar_with_ret(char c)
{
	return(write(1, &c, 1));
}

int	ft_strlen(const char *str)
{
	int i;
	
	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	ft_putstr(const char *str, int strlen)
{
	int i;

	i = strlen;
	if (i)
		write (1, str, i);
	return (i);
}

int	ft_atoi(const char *str, int *i)
{
	int	num;
	
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - 48);
		str++;
	}
	return (num);
}

int	printstr(const char *str, t_flags *flags)
{
	int	printed;
	int limit;
	int strlen;
	int width_size;

	printed = 0;
	limit = flags->dot_field;
	strlen = ft_strlen(str);
	if (limit < strlen)
		strlen = limit;
	width_size = flags->width_field;
	if (flags->tsix == 1)
		printed += ft_putstr(str, strlen);
	while (width_size != strlen)
	{
		printed += ft_putchar_with_ret(' ');
		width_size--;
	}
	if (flags->tsix == 0)
		printed += ft_putstr(str, strlen);
	return (printed);
}

int	pathfinder(const char *str, va_list args, t_flags *flags, int *i)
{
	int	printed;

	printed = 0;
	(*i)++;
	if (str[(*i)] == '-')
	{
		flags->tsix = 1;
		(*i)++;
	}
	flags->width_field = ft_atoi(str, i);
	while (str[(*i)] >= '0' && str[(*i)] <= '9')
		(*i)++;
	if (str[(*i)++] == '.')
	{
		flags->dot = 1;
		flags->dot_field = ft_atoi(str, i);
		while (str[(*i)] >= '0' && str[(*i)] <= '9')
			(*i)++;
	}
	printed += printstr(va_arg(args, char *), flags);
	(*i)++;
	return (printed);
}


int	ft_sprintf(const char *str, ...)
{
	int printed;
	int	i;
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
	return (printed);
}

int main(void)
{
	const char *str = "myboy";
	int ret = 0;
	ret = ft_sprintf("voici ma string : %-8.4s", str);
	printf("\n");
	printf("%d", ret);
}