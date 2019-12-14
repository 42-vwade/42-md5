/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:55:59 by viwade            #+#    #+#             */
/*   Updated: 2019/12/14 02:05:35 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

unsigned
	ff(i, f, a, mode)
	unsigned	i;
	unsigned	*f;
	int			a[3];
	int			mode;
{
	if (ft_tolower(mode) == 'f')
		f[0] = (a[0] & a[1]) | (~a[0] & a[2]);
	else if (ft_tolower(mode) == 'g')
		f[0] = (a[0] & a[2]) | (~a[2] & a[1]);
	else if (ft_tolower(mode) == 'h')
		f[0] = a[0] ^ a[1] ^ a[2];
	else if (ft_tolower(mode) == 'i')
		f[0] = a[1] ^ (a[0] |~ a[2]);
	return (i);
}

unsigned
	m_rr(value, shift)
unsigned	value;
unsigned	shift;
{
	return ((value << shift) | (value >> (32 - shift)));
}

void
	m_rotate(unsigned *a, unsigned *b, unsigned *c, unsigned *d)
{
	a[0] = d[0];
	d[0] = c[0];
	c[0] = b[0];
}