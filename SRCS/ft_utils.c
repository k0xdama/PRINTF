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

#include "../INCLUDES/ft_printf.h"

void	up_struct(t_flags *flags)
{
	flags->width_field = 0;
	flags->dot_field = 0;
	flags->zero = 0;
	flags->htag = 0;
	flags->hex_cap = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->dash = 0;
	flags->dot = 0;
}

int	ft_putchar_with_ret(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	printed;
	int	len;

	printed = 0;
	len = ft_strlen(str);
	if (str == NULL)
	{
		printed += write(1, "(null)", 6);
		return (printed);
	}
	else
	{
		printed += write(1, str, len);
		return (printed);
	}
}

int	ft_nbrlen(long int nbr, int base, t_flags *flags)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i = 1;
	if (nbr == 0 && (flags->dot == 1 && flags->dot_field == 0))
		i = 0;
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
		while (nbr)
		{
			nbr /= 16;
			i++;
		}
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
