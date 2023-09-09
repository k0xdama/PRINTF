/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 04:14:55 by pmateo            #+#    #+#             */
/*   Updated: 2023/09/09 18:16:55 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../INCLUDES/ft_printf.h"

int	ft_printchar(char c, t_flags *flags)
{
	int	printed;
	int	width_size;

	printed = 0;
	width_size = flags->width_field;
	if (flags->width_field > 0)
	{
		width_size = flags->width_field;
		if (flags->tsix == 1)
			printed += ft_putchar_with_ret(c);
		while (width_size > 1)
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

