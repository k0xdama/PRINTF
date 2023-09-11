/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittestprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 01:05:19 by pmateo            #+#    #+#             */
/*   Updated: 2023/09/11 17:36:05 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int ret = 0;
	// char *str = "ntm";
	ret = printf("%u", 42);
	ret = printf("some naugty tests: %s", "0000%");
	printf("\n");
	printf("ret = %d", ret);
	}
