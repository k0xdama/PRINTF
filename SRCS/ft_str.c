/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:31 by pmateo            #+#    #+#             */
/*   Updated: 2023/09/10 18:58:32 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

static	int	ft_strlen(const char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (0);
}

int	ft_printstr(const char *str, t_flags *flags)
{
	int	printed;
	int	limit;
	int	strlen;
	int	width_size;

	printed = 0;
	limit = flags->dot_field;
	strlen = ft_strlen(str);
	if (limit < strlen)
		strlen = limit;
	width_size = flags->width_field;
	if (flags->dash == 1)
		printed += ft_putstr(str, strlen);
	while (width_size != strlen)
	{
		printed += ft_putchar_with_ret(' ');
		width_size--;		
	}
	if (flags->dash == 0)
		printed += ft_putstr(str, strlen);
	return (printed);
}

