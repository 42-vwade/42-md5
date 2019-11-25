/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:49:44 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**		FLOAT
*/

static FT_SIZE
	convert_f(t_format *o)
{
	width_o(o);
	append_s(o);
	return (3);
}

/*
**	static FT_SIZE
**		convert_f(t_format *o)
**	{
**		size_t	ret;
**		size_t	len;
**
**		ret = 0;
**		o->p.precision = !(o->p.tick & 0b100) ? 6 : o->p.precision;
**		o->v = infinite_double(*(double*)o->v, o->p.precision);
**		len = ft_strlen(o->v);
**		o->p.width = MAX((LL)(o->p.width - len), 0);
**		if (o->p.flags & (plus + space + neg))
**			modify_o(o, "sign");
**		else
**			modify_o(o, "pad");
**		ret = write(1, o->v, ft_strlen(o->v));
**		free(o->v);
**		return (ret);
**	}
*/

static void
	is_float(t_format *o)
{
	MATCH(!(o->p.tick & 0b100), o->p.precision = 6);
	MATCH(o->p.length > 8,
		o->v = infinite_double(*(long double*)o->v, o->p.precision));
	ELSE(o->v = infinite_double((long double)*(double*)o->v, o->p.precision));
}

static int
	is_anomaly(long double num, t_format *o)
{
	FT_NBR	n;

	n.d = NULL;
	if ((n.length = (num != num) * 3))
		n.d = ft_strdup("nan");
	else if ((n.length = (num == INFINITY) * 3))
		n.d = ft_strdup("inf");
	else if ((n.length = (num == -INFINITY) * 4))
		n.d = ft_strdup("-inf");
	return (n.d && (o->v = n.d));
	return (n.length);
}

int
	parse_f(t_format *o)
{
	size_t		ret;
	double		num;
	long double	ld;

	ret = 0;
	MATCH(o->p.length <= 8, o->v = &num);
	ELSE(o->v = &ld);
	MATCH(o->p.length <= 8, num = va_arg(o->ap, double));
	ELSE(ld = va_arg(o->ap, long double));
	o->p.flags |= (num < 0) << 7;
	MATCH(o->p.length > 8, ret = is_anomaly(*(long double*)o->v, o));
	ELSE(ret = is_anomaly((long double)*(double*)o->v, o));
	MATCH(ret, RET(ret));
	ELSE(is_float(o));
	return (convert_f(o));
}
