/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:49:44 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**		CHAR
*/

static void
	width_c(t_format *o)
{
	o->v = encode_output(0, o->v);
	MATCH(!o->p.width, RET);
	MATCH(!(o->p.width -= !!o->v), RET);
	o->pad = encode_output(0, ft_memset(
		ft_strnew(o->p.width), o->p.flags & zero ? '0' : ' ', o->p.width));
}

static FT_SIZE
	convert_c(t_format *o)
{
	MATCH(o->str[0] == '%', *(ull_t*)o->v = '%');
	MATCH(o->p.length == l, o->v = encode_utf8((int[2]){*(ll_t *)o->v, 0}));
	ELSE(o->v = ft_strdup((char[2]){*(char *)o->v, 0}));
	width_c(o);
	append_s(o);
	return (1);
}

/*
**	Returns number of bytes written to stdout.
**
**	If a length is specified, a null-terminated wchar_t is retrieved.
**	An uppercase specifier (C) is treated as if the length flag was given.
**	Otherwise, a null-terminated char is retrieved.
*/

int
	parse_c(t_format *o)
{
	ull_t	c;

	o->v = &c;
	MATCH(ft_isuppercase(o->str[0]) || o->p.length > 8, o->p.length = l);
	MATCH(o->str[0] == 'r', c = *(ull_t*)o->tmp);
	OR(o->str[0] != '%', cast_o(o));
	return (convert_c(o));
}
