/* *****œ:x********************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:04:01 by pmateo            #+#    #+#             */
/*   Updated: 2023/08/20 05:43:36 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../INCLUDES/ft_printf.h"

void	up_struct(t_flags *flags)
{
	flags->width_field = 0;
	flags->dot_field = 0;
	flags->zero = 0;
	flags->htag = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->tsix = 0;
	flags->dot = 0;
}

int ft_putchar_with_ret(char c)
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

int ft_nbrlen(int nbr, int base)
{
    int i;

    i = 0;
	if (nbr == 0)
		i = 1;
	if (base == 10)
	{
		while (nbr)
		{
			nbr /= 10;
			i++;
		}
	}
	else if (base == 16)
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
