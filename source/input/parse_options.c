/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:18:05 by viwade            #+#    #+#             */
/*   Updated: 2019/11/04 04:51:35 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int	get_string(t_option *o, char *s, char *v)
{
	t_object	obj;

	ft_bzero(&obj, sizeof(obj));
	if (*s)
		obj.data = s;
	else if (v)
		obj.data = v;
	obj.type = string;
	obj.length = ft_strlen(obj.data);
	obj.type = string;
	obj.free = 0;
	return (!*s);
}

/*
**	If
**	If -s, stop parsing. If not end of arg, digest remainder as string.
*/

static int	get_option(t_option *o, char *s, char *v, int n)
{
	char	*marker;


	while (s[0])
	{
		if (s[0] == 's' && n)
			return (get_string(o, &s[1], v));
		if (s[0] == 's' && !n)
			return (parse_error(no_param));
		else if (s[0] == 'p')
			o->p = 1;
		else if (s[0] == 'q' && !(o->r = 0))
			o->q = 1;
		else if (!o->q && s[0] == 'r')
			o->r = 1;
		else if (s[0] == 't')
			o->t = 1;
		else if (s[0] == 'x')
			o->x = 1;
		s++;
	}
	return (0);
}

static void	print_option(t_option *o)
{
	ft_printf(
		"flag: s: %i\n"
		"flag: p: %i\n"
		"flag: q: %i\n"
		"flag: r: %i\n"
		"flag: t: %i\n"
		"flag: x: %i\n",
		o->s, o->p, o->q ,o->r ,o->t ,o->x
	);
}

void	parse_option(t_config *config, int n, char **v)
{
	int			i;
	t_option	o;

	ft_bzero(&o, sizeof(t_option));
	o.queue = &config->queue;
	i = 0;
	while (++i < n)
	{
		if (v[i][0] == '-' && v[i][1] == '-')
			break ;
		else if (v[i][0] == '-' && v[i][1])
			i += get_option(&o, &v[i][1], i + 1 < n ? v[i + 1] : 0, n - i);
	}
	print_option(&o);
	exit(2);
	return (o);
}
