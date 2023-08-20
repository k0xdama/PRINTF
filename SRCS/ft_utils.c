/* ************************************************************************** */
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

void	up_struct(t_flags f_bool, t_flags *f_fields)
{
	f_fields->width_field = malloc(sizeof(int));
	f_fields->zero_field = malloc(sizeof(int));
	f_fields->tsix_field = malloc(sizeof(int));
	f_fields->dot_field = malloc(sizeof(int));
	*f_fields->width_field = 0;
	*f_fields->zero_field = 0;
	*f_fields->tsix_field = 0;
	*f_fields->dot_field = 0;
	f_bool.zero = 0;
	f_bool.h_tag = 0;
	f_bool.space = 0;
	f_bool.plus = 0;
	f_bool.tsix = 0;
	f_bool.dot = 0;
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