/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
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
	print_bits(int octal)
{
	unsigned char ndx;

	ndx = 0x80;
	if (octal == -1)
		return ;
	while (ndx)
	{
		ft_putchar(((unsigned char)octal & ndx) ? '1' : '0');
		ndx = ndx >> 1;
	}
}
