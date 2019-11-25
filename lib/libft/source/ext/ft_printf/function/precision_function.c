/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:05:10 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:49:44 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Ensure o->v is allocated before use.
*/

/*
**	Produces a sign
**	If the number is negative, the sign is shifted to the left of all zeros.
**	If padding length is zero, no modifications to value are made.
**	If no precision is given, no modifications are made.
*/

static void
	sign_i(t_format *o)
{
	o->sign = 0;
	MATCH(ft_strchr("ubox", ft_tolower(*o->str)), RET);
	MATCH(!((plus + space + neg) & o->p.flags), RET);
	MATCH(o->p.flags & space, o->sign = " ");
	OR(o->p.flags & plus, o->sign = "+");
	OR(o->p.flags & neg, o->sign = "-");
	if (((char*)o->v)[0] == '-' && o->sign && *o->sign == '-')
	{
		o->tmp = o->v;
		o->v = ft_strdup(&((char*)o->v)[1]);
		ft_memdel(&o->tmp);
	}
}

/*
**	#define A_M(a, b) ((a) & (b))
**	#define B_M(a, b) (!((a) & (b)))
**	#define C_M(a,b,c) (A_M(a,b) && B_M(a,c))
**	#define SIGN_M(f,a,b,c) C_M(f,a,c)?'+':C_M(f,b,c)?' ':'-'
**	static void
**		sign_i(t_format *o)
**	{
**		if (!((plus + space + neg) & o->p.flags &&
**				ft_strchr("diefga", ft_tolower(*o->str))))
**			return ;
**		o->sign = (char[2]){SIGN_M(o->p.flags, plus, space, neg), 0};
**		if (ft_isdigit(*(char*)o->v))
**			o->v = ft_append(o->sign, o->v, 2);
**		else
**			((char*)o->v)[0] = o->sign[0];
**	}
*/

/*
**	Creates a zero-padded number.
**	If the number is negative, the sign is shifted to the left of all zeros.
**	If padding length is zero, no modifications to value are made.
**	If no precision is given, no modifications are made.
*/

void
	precision_o(t_format *o)
{
	o->len = ft_strlen(o->v);
	MATCH(o->p.tick & 4, o->p.precision = MAX(o->p.precision, o->len));
	ELSE(o->p.precision = o->len);
	o->len = o->p.precision;
}

void
	precision_i(t_format *o)
{
	sign_i(o);
	MATCH(ft_tolower(*o->str) != 'p' && !(o->p.tick & 4), RET);
	o->len = ft_strlen(o->v);
	o->p.precision = MAX((ll_t)(o->p.precision - o->len), 0);
	MATCH(!o->p.precision, RET);
	o->z_pad = ft_memset(ft_strnew(o->p.precision), '0', o->p.precision);
}

void
	precision_s(t_format *o)
{
	if ((o->v && !*(char*)o->v) || (o->p.tick & 4 && !o->p.precision))
		o->v = 0;
	if (!o->v)
		return ;
	if (o->p.tick & 4)
		o->p.precision = MIN(ft_strlen(o->v), o->p.precision);
	if ((o->p.length & (l + ll) || ft_isuppercase(o->str[0])))
	{
		if (o->p.tick & 4)
			o->v = encode_utf8_w(o->v, o->p.precision);
		else
			o->v = encode_utf8(o->v);
	}
	else
	{
		if ((o->p.tick & 4))
			o->v = ft_strsub(o->v, 0, o->p.precision);
		else
			o->v = ft_strdup(o->v);
	}
}
