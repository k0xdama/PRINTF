/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:31 by pmateo            #+#    #+#             */
/*   Updated: 2023/08/15 08:52:58 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		len = 6;
		write(1, "(null)", len);
		return (len);
	}
	else 
	{
		while(str[len])
		{
			write(1, &str[len], 1);
			len++;
		}
		return (len);
	}
}

// int	main(void)
// {
// 	char *str = NULL;
// 	int ret1;
// 	int ret2;
// 	ret1 = ft_putstr(str);
// 	ret2 = printf("%s", str);
// 	printf("ret1 = %d\nret2 = %d", ret1, ret2);
// 	return (0);
// }

