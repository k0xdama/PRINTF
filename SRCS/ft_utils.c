/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:04:01 by pmateo            #+#    #+#             */
/*   Updated: 2023/08/19 04:16:17 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_putchar_with_ret(char c)
{
    return (write(1, &c, 1));
}

int ft_nbrlen(int nb)
{
    int len;
    
    len = 0;
    if (nb < 0)
        len += 1;
    while (nb != 0)
    {
        nb /= 10;
        len++;
    }
    return (len);
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

int main(void)
{
    int nb = -424266;
    int ret1 = ft_putnbr(nb);
    int ret2 = printf("%d", nb);
    printf("\n"); 
    printf("ret1 = %d\n", ret1);
    printf("ret2 = %d", ret2);    
}