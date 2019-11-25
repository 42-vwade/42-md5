/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 00:45:55 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:49:44 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void
	hash_o(t_format *o)
{
	char	c;
	char	z;

	MATCH(!(hash & o->p.flags), RET);
	c = ft_tolower(o->str[0]);
	z = !ft_atoi(o->v);
	if (ft_cmp(c, 'o') && !o->z_pad
		&& (!z || (z && (o->p.tick & 4 && !o->p.precision))))
		o->prefix = "0";
	else if ((ft_cmp('x', c) && !z) || ft_cmp('p', c))
		o->prefix = "0x";
	else if (ft_strchr("aefg", c) && !ft_strchr(o->v, '.'))
		o->v = ft_append(o->v, ".", 1);
	if (ft_cmp(c, 'g'))
		;
}
