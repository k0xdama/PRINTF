/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:36:02 by pmateo            #+#    #+#             */
/*   Updated: 2023/08/23 21:26:47 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void	up_struct(t_flags *flags)
{
	flags->width_field = 0;
	flags->tsix = 0;
}

int	ft_putchar_with_ret(char c)
{
	return(write(1, c, 1));
}

int	ft_atoi(const char *str)
{
	int	num;
	
	num = 0;
	while (*str <= '0' || *str >= '9')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - 48);
		str++;
	}
	return (num);
}

int	printchar(char c, t_flags flags)
{
	
}

int main(void)
{
	const char *str = "-20c";
	printf("retour de atoi : %d\n", ft_atoi(str));
}