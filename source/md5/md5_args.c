/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:48:38 by viwade            #+#    #+#             */
/*   Updated: 2019/12/24 02:03:37 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

static t_bool
	parse(char *s, t_option *o)
{
	if (!s || !s[0] || (s[0] == '-' && s[1] == '\0'))
		return (0);
	if (s[0] == '-')
		return (0);
	while((s)[0])
		if (s[0] == 'p' && (s++ || 1))
			o->p += !!(o->p % 256) + !o->p;
		else if (s[0] == 'q' && !(o->r = 0) && (s++ || 1))
			o->q = 1;
		else if (s[0] == 'r' && !o->q && (s++ || 1))
			o->r = 1;
		else if (s[0] == 's' && (o->s = 1) && (s++ || 1))
			return (0);
	return (1);
}

t_bool
	md5_args(int n, char **v, t_md5 *m)
{
	int		i;
	int		c;

	if (((i = !n)))
		return (0);
	while (v[i][c = 0] != '-' && i < n)
		if (++i == n)
			return (0);
	while (i < n && (i += 1))
		if ((c += !(v[i - 1][0] == '-' && parse(&v[i - 1][1], &m->option))))
			break ;
	return (c);
}

/*
**	RUNDOWN
**	Available options: p, q, r, s
**	Order of precedence:
**	-	p: Read stdin to stdout, then display stdin hash on output
**		-	Display contents of file (as it is read, presumably)
**		-	If given, an attempt to read stdin must be made before doing
**			anything else.
**	-	q: Quiet mode (Meaning?) -- print only hash
**	-	r: Reverse display. Print md5 hash followed by input string.
**	-	s:
*/
