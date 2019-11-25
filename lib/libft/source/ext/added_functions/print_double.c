/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 07:18:13 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#define D_MASK (0xFFFFFFFF00000000u)

static int
	get_decimal(ld_t n, int p)
{
	while (p--)
	{
		n = ((n) - (uint8_t)(n)) * 10;
	}
	return ((uint8_t)n);
}

/*
**	return ((int)((n - (int)n) * 10) >= 5);
*/

static void
	round_up(ld_t *n, unsigned p, unsigned num)
{
	if ((num = get_decimal(n[0], p + 1)) >= 5)
		n[0] += (ld_t)1 / ft_power(10, MAX(0, p));
}

static void
	write_decimal(ld_t n, size_t p, size_t i)
{
	write(1, ".", 1);
	while (p - i++)
		ft_putchar(48 + get_decimal(n, i));
}

void
	print_double(ld_t n, unsigned int precision)
{
	if (n < 0 && write(1, "-", 1))
		n = ABS(n);
	round_up(&n, precision, 0);
	ft_putnbr((long)n);
	if (precision)
		write_decimal(ABS(n - (long)n), precision, 0);
}
