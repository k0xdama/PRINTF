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

#include <unistd.h>
#include <stdio.h>
#include "../INCLUDES/ft_printf.h"

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

int	ft_atoi(char *str)
{
	
}

int	is_flags(char c, char *str)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (c == str[i])
			ret++;
		i++;
	}
	return (ret);
}

void	up_struct(t_flags *flags)
{
	flags->width_field = 0;
	flags->zero_field = 0;
	flags->tsix_field = 0;
	flags->dot_field = 0;
	flags->zero = 0;
	flags->htag = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->tsix = 0;
	flags->dot = 0;
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
