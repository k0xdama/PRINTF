/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u4s2e0r <u4s2e0r@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 00:54:29 by u4s2e0r           #+#    #+#             */
/*   Updated: 2023/09/04 01:18:29 by u4s2e0r          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_putchar_with_ret(char c)
{
    return(write(1, &c, 1));
}

int ft_hexlen(int nbr)
{
    int i;

    i = 0;
    if (nbr == 0)
        i = 1;
    while (nbr != 0)
    {
        nbr /= 16;
        i++;
    }
    return (i);
}

int ft_puthex(int nbr, int bool)
{
    int len;
    long nbl;
    char *basemaj;
    char *basemin;

    len = ft_hexlen(nbr);
    nbl = nbr;
    basemaj = "0123456789ABCDEF";
    basemin = "0123456789abcdef";
    if (nbl <= 16 && bool == 0)
        ft_putchar_with_ret(basemin[nbl]);
    else if (nbl <= 16 && bool == 1)
        ft_putchar_with_ret(basemaj[nbl]);
    if (nbl > 16)
    {
        ft_puthex(nbl / 16, bool);
        ft_puthex(nbl % 16, bool);
    }
    return (len);
}

int main(void)
{
    int ret = 0;
    int nb = -42;
    ret = ft_puthex(nb, 1);
    printf("\n");
    printf("%d\n", ret);
}