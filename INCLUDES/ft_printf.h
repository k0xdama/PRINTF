/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:45:42 by pmateo            #+#    #+#             */
/*   Updated: 2023/08/21 20:15:51 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef	struct s_flags
{
	int			width_field;
	int			zero_field;
	int			tsix_field;
	int			dot_field;
	int			zero;
	int			htag;
	int			space;
	int			plus;
	int			tsix;
	int			dot;
}	t_flags;








int				ft_strlen(char *str);
int				ft_nbrlen(int nb);
int				ft_hexalen(unsigned int nb);
int				ft_putchar_with_ret(char c);
int				ft_putnbr(int nb);
int				ft_atoi(char *str, int *i);
void			up_struct(t_flags *flags);




















#endif