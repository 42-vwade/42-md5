/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:57:50 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:49:44 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define C_RESET		0
#define C_BLACK		1
#define C_RED		2
#define C_GREEN		3
#define C_YELLOW	4
#define C_BLUE		5
#define C_MAGENTA	6
#define C_CYAN		7
#define C_WHITE		8
#define C_B_BLACK	9
#define C_B_RED		10
#define C_B_GREEN	11
#define C_B_YELLOW	12
#define C_B_BLUE	13
#define C_B_MAGENTA	14
#define C_B_CYAN	15
#define C_B_WHITE	16
#define CG7(s,f)	f(s)
#define CG6(s,f)		C_BLACK
#define CG5(s,f)		!!f("white",s)	 ? C_WHITE	 : CG6(s,f)
#define CG4(s,f)		!!f("magenta",s) ? C_MAGENTA : CG5(s,f)
#define CG3(s,f)		!!f("cyan",s)	 ? C_CYAN	 : CG4(s,f)
#define CG2(s,f)		!!f("yellow",s)	 ? C_YELLOW	 : CG3(s,f)
#define CG1(s,f)		!!f("blue",s)	 ? C_BLUE	 : CG2(s,f)
#define CG0(s,f)		!!f("green",s)	 ? C_GREEN	 : CG1(s,f)
#define COLOR_GET(s,f)	!!f("red",s)	 ? C_RED	 : CG0(s,f)

static int
	convert_a(t_format *o)
{
	char	n;
	char	**m;

	m = (char *[]){"\x1b[3", "\x1b[38;5;", "m", ";1m"};
	n = *(char *)o->v;
	MATCH(!o->v, o->v = ft_append(m[0], "0", 0));
	MATCH(n < 8, o->v = ft_append(m[0], ft_append(ft_itoa(n), m[2], 1), 2));
	OR(n < 16, o->v = ft_append(m[0], ft_append(ft_itoa(n - 8), m[3], 1), 2));
	OR(n >= 16, o->v = ft_append(m[1], ft_append(ft_itoa(n), m[2], 1), 2));
	append_s(o);
	return (0);
}

static ull_t
	synthesize_color(char *s)
{
	char	bright;
	char	*tmp;
	ull_t	col;

	MATCH(!s, RET(0));
	col = 0;
	bright = 0;
	MATCH(!(s = ft_strtrim(s)), ft_error("synth_col (error) : trim 1"));
	ft_strtolower(&s);
	tmp = s;
	MATCH(bright = 8 * ft_strnequ("bright", s, 6), ((s += 6) || 1)
		&& (s = ft_strtrim(s)));
	MATCH(bright, ft_memdel((void**)&tmp));
	MATCH(!(col = (unsigned char)COLOR_GET(s, ft_strequ) + bright),
		(s[0] && s[1]) && (col = (unsigned char)CG7(s, ft_atoi)));
	return (col);
}

int	parse_a(t_format *o)
{
	ull_t	color;

	color = 0;
	MATCH(!o->color, o->color = 1);
	o->v = &color;
	MATCH(o->p.flags & hash, o->v = va_arg(o->ap, void *));
	ELSE(color = (unsigned char)va_arg(o->ap, int));
	MATCH(!o->v && !color, RET(convert_a(o)));
	MATCH(o->v != &color, ((color = synthesize_color(o->v)) || 1));
	MATCH(o->v != &color, ((color -= 1) || 1)
		&& (o->v = &color));
	return (convert_a(o));
}
