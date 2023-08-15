/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignednbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:40 by pmateo            #+#    #+#             */
/*   Updated: 2023/08/15 10:05:05 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_unbrlen(int nb)
{
    int len;
    
    len = 0;
    while (nb != 0)
    {
        nb /= 10;
        len++;
    }
    return (len);
}

int	ft_uputnbr(unsigned int nb)
{
	unsigned long	nbl;
	int len;

	nbl = nb;
	len = ft_unbrlen(nb);
	if (nbl <= 9)
		ft_putchar(nbl + 48);
	if (nbl > 9)
	{
		ft_uputnbr(nbl / 10);
		ft_uputnbr(nbl % 10);
	}
	return (len);
}

// int	main(void)
// {
// 	unsigned int nb = 4568001447;
// 	int ret1 = ft_uputnbr(nb);
// 	printf("\n");
// 	int ret2 = printf("%u", nb);
// 	printf("\n");
// 	printf("ret1 = %d\n", ret1);
// 	printf("ret2 = %d\n", ret2);
// }
