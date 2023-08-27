/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:18:58 by pmateo            #+#    #+#             */
/*   Updated: 2023/08/24 20:21:26 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strlen(const char *str)
{
	int i;
	
	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	ft_putstr(const char *str)
{
	int i;

	i = ft_strlen(str);
	if (i)
		write (1, str, i);
	return (i);
}

int	main(void)
{
	const char *str = "printmoicetrucboy";
	ft_putstr(str);
}