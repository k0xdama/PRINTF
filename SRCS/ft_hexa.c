/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:43 by pmateo            #+#    #+#             */
/*   Updated: 2023/08/16 21:02:55 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_hexalen(unsigned int nb)
{
    int    len;

    len = 0;
    while (nb != 0)
    {
        nb /= 16;
        len++;
    }
    return (len);
}

int ft_puthexa(unsigned int, const char flag)
{
    
}

int main(void)
{
    unsigned int nb = 420;
    printf("%x\n", nb);
}