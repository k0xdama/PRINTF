/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:36 by pmateo            #+#    #+#             */
/*   Updated: 2023/09/10 18:57:31 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int ft_ptrlen(uintptr_t ptr)
{
    int i;

    i = 0;
	while (ptr)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}

static	int ft_putptr(uintptr_t ptr)
{
    int	len;
    char	*base;

    len = ft_ptrlen(ptr);
	base = "0123456789abcdef";
    if (ptr <= 16)
		ft_putchar_with_ret(base[ptr]);
	if (ptr > 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	return (len);
}

static	int	dash_on(uintptr_t ptr, int *width_size)
{
	int	printed;

	printed = 0;
	printed += ft_putstr("0x", 2);
	printed += ft_putptr(ptr);
	while ((*width_size)-- >= 0)
		printed += ft_putchar_with_ret(' ');
	return (printed);
}

static	int	dash_off(uintptr_t ptr, int *width_size)
{
	int	printed;

	printed = 0;
	while((*width_size)-- >= 0 )
		printed += ft_putchar_with_ret(' ');
	printed += ft_putstr("0x", 2);
	printed += ft_putptr(ptr);
	return (printed);
}
int ft_printptr(uintptr_t ptr, t_flags *flags)
{
    int printed;
    int ptrlen;
    int width_size;

    printed = 0;
    ptrlen = ft_nbrlen(ptr, 16);
    width_size = flags->width_field - (ptrlen + 2);
    if (flags->dash == 1)
        printed += dash_on(ptr, &width_size);
    else if (flags->dash == 0)
        printed += dash_off(ptr, &width_size);
    return (printed);
}

// int main(void)
// {
//     char *str = "string";
//     char **ptr;
//     ptr = &str;
//     // printf("%p\n", ptr);
//     write(1, &ptr, );
// }
