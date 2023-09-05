/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittestprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 01:05:19 by pmateo            #+#    #+#             */
/*   Updated: 2023/09/06 00:16:15 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int ret = 0;
	// printf("%30d", 2147483647);
	// printf("\n");
	// printf("%-30d", 2147483647);
	// printf("\n");
	// printf("%-.9d", 2147483647);
	// printf("\n");
	// printf("%#9X", 42);
	// printf("\n");
	// printf("%042d\n", 42);
	// printf("%+010d", 42);
	// printf("\n");
	// printf("%#13d", 42);
	// printf("\n");
	// ret = printf("%-20c", '#');
	// printf("\n");
	// ret = printf("%-.4s", "myboy");
	// printf("\n");
	// ret = printf("%- 07d", 42);
	// printf("\n");
	// ret = printf("%-8.3u", 42);
	// printf("\n");
	ret = printf("%012.4x", 42);
	printf("\n");
	printf("%d\n", ret);
}
