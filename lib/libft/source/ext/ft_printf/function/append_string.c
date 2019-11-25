/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:15:36 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:49:44 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void
	append_s(t_format *o)
{
	char	left;
	char	zer0;

	left = o->p.flags & minus;
	zer0 = o->p.flags & zero;
	MATCH(o->prefix && o->z_pad, o->z_pad = ft_append(o->prefix, o->z_pad, 2));
	OR(o->prefix && o->pad && zer0, o->pad = ft_append(o->prefix, o->pad, 2));
	OR(o->prefix, o->v = ft_append(o->prefix, o->v, 2));
	MATCH(o->sign && o->z_pad, o->z_pad = ft_append(o->sign, o->z_pad, 2));
	OR(o->sign && o->pad && zer0, o->pad = ft_append(o->sign, o->pad, 2));
	OR(o->sign, o->v = ft_append(o->sign, o->v, 2));
	MATCH(o->z_pad, o->v = ft_append(o->z_pad, o->v, 3));
	MATCH(left, o->v = ft_append(o->v, o->pad, 3));
	OR(o->pad, o->v = ft_append(o->pad, o->v, 3));
	MATCH(o->v && ANY2(o->str[0], 'X', 'P'), ft_strcapitalize(o->v));
}
