/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:48:38 by viwade            #+#    #+#             */
/*   Updated: 2019/12/14 02:11:19 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

static t_bool
	parse(char *s, t_option *o)
{
	t_option	param;

	if (!s || !s[0] || (s[1] == '-' && s[2] == '\0'))
		return (0);
	if (s[0] == '-')
		return (0);
	while((++s)[0])
		if (s[0] == 's' && (o->s = 1))
			return (0);
		else if (s[0] == 'p')
			o->p = 1;
		else if (s[0] == 'q' && !(o->r = 0))
			o->q = 1;
		else if (s[0] == 'r' && !o->q)
			o->r = 1;
		else if (s[0] == 's')
			o->s = 1;
		else
			;
}

t_bool
	md5_args(int n, char **v, t_md5 *m)
{
	static int		c;
	static t_option option;

	if (!n)
		return md5(&(t_config){
			0, 0, ft_basename(v[0]), (char[32]){}, 0, 0, 0, 0, 0, md5});
	else
		while (++c < n)
		{
			if (v[c][0] == '-' && parse(v[c], &option))
				if (option.s)
					;
			else
				break ;
		}
}

/*
**	RUNDOWN
**	Available options: p, q, r, s
**	Order of precedence:
**	-	p: Read stdin to stdout, then display stdin hash on output
**		-	Display contents of file (as it is read, presumably)
**		-	If given, an attempt to read stdin must be made before doing
**			anything else.
**	-	q: Quiet mode (Meaning?)
**	-	r: Reverse display. Print md5 hash followed by input string.
**	-	s:
*/
