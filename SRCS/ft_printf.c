/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:38 by pmateo            #+#    #+#             */
/*   Updated: 2023/08/15 02:22:12 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
int ft_printf(const char *str, ...)
{
    size_t  i;

    while(str[i])
    {
        if(str[i] == '%')
        {
            if(str[i+1] == 'd' || str[i+1] == 'i')
                ft_putnbr();
            else if (str[i+1] == 'u')
                ft_uputnbr();
            else if (str[i+1] == 'c')
                ft_putchar();
            else if (str[i+1] == 's')
                ft_putstr();
            else if (str[i+1] == 'x' || str[i+1] == 'X')
                ft_puthex();
            else if (str[i+1] == 'p')
                ft_putptr();
            else if (str[i+1] == '%')
                ft_putpercent();
        }
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}


int main(void)
{
    int nb = 42;
    ft_printf("blabla = %d", 42);
}