/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/11/25 10:58:21 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define PLUS(n) ((n) & (1 << 0))
#define MINUS(n) ((n) & (1 << 1))
#define ZERO(n) ((n) & (1 << 2))
#define HASH(n) ((n) & (1 << 3))
#define SPACE(n) ((n) & (1 << 4))
#define U_HH(n)	n = (unsigned char)(n)
#define U_H(n)	n = (unsigned short)(n)
#define U_L(n)	n = (unsigned long)(n)
#define U_LL(n)	n = (unsigned long long)(n)
#define CHH(a)	(a & hh)
#define CH(a)	(a & h)
#define CL(a)	(a & l)
#define CLL(a)	(a & ll)
#define U_LENGTH(a, n, t)	if(a){t}else{n = (unsigned)n;}

/*
**		OCTAL / HEX
*/

static FT_SIZE
	convert_x(t_format *o)
{
	char	u;
	char	pad[64];
	size_t	l;
	size_t	len;

	u = ft_tolower(o->str[0]);
	l = o->p.length * 8;
	MATCH(u == 'b', (u = 2) && ft_memset(pad, 0, l));
	ELSE(u = 16 >> (u == 'o'));
	MATCH(o->p.tick & 4 && !o->p.precision && !*(ll_t*)o->v, o->v = 0);
	ELSE(o->v = ft_itoa_base(*(ull_t*)o->v, u));
	MATCH(u == 2 && (len = ft_strlen(o->v) % l) && ft_memset(pad, '0', l - len),
		o->v = ft_append(pad, o->v, 2));
	precision_i(o);
	width_o(o);
	append_s(o);
	return (1);
}

/*
**	Conditions already taken care of.
**	Input specifier shall be o / O / x / X / p / P
**	Output shall be in in either base 16, or base 8 if o / O is given
*/

int
	parse_x(t_format *o)
{
	ull_t	num;

	o->v = &num;
	MATCH(o->p.length > 8, o->p.length = l);
	MATCH(o->p.tick & (1 << 6) && !o->p.precision, (o->p.tick &= ~(1 << 2)));
	MATCH(ft_tolower(o->str[0]) == 'p', o->p.length = l);
	MATCH(ft_tolower(o->str[0]) == 'p', o->p.flags |= hash);
	MATCH(o->p.tick & 4, o->p.flags &= ~zero);
	cast_o(o);
	return (convert_x(o));
}
