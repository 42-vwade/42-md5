/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_64bits_recursive.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 21:59:40 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void
	print_64bits_recursive(uint64_t llu)
{
	unsigned char ndx;

	if (llu > 0xFF)
		print_bits(llu >> 8);
	ndx = 0x80;
	while (ndx)
	{
		ft_putchar(((unsigned char)llu & ndx) ? '1' : '0');
		ndx = ndx >> 1;
	}
	ft_putchar('\n');
}
