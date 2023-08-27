/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:18:15 by pmateo            #+#    #+#             */
/*   Updated: 2023/08/27 19:16:35 by pmateo           ###   ########.fr       */
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

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
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

int	ft_putnbr(int nb)
{
	long	nbl;
    int     len;
    
    len = ft_nbrlen(nb);
	nbl = nb;
	if (nbl < 0)
	{
		write(1, "-", 1);
		nbl *= -1;
	}
	if (nbl >= 0 && nbl <= 9)
		ft_putchar(nbl + 48);
	if (nbl > 9)
	{
		ft_putnbr(nbl / 10);
		ft_putnbr(nbl % 10);
	}
    return (len);
}

int pathfinder(const char *str, va_list args, t_flags flags, int *i)
{
    int printed;

    printed = 0;
    (*i)++;
    
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
            printed += ft_putchar_with_ret(str[i]);
        i++;
    }
    va_end(args);
    return(printed);
}

int main(void)
{
    
}

