/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:31 by pmateo            #+#    #+#             */
/*   Updated: 2023/09/12 03:20:21 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;
	
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
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
	if (limit < strlen && flags->dot == 1)
		strlen = limit;
	width_size = flags->width_field;
	if (flags->dash == 1)
		printed += ft_putstr(str);
	while (width_size > strlen)
	{
		printed += ft_putchar_with_ret(' ');
		width_size--;		
	}
	if (flags->dash == 0)
		printed += ft_putstr(str);
	return (printed);
}

