/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:18:05 by viwade            #+#    #+#             */
/*   Updated: 2019/10/17 12:06:28 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

static int	ft_brackets(char *s)
{
	char	c;

	while
}

static void	get_string(t_option *o, char *s, char *v)
{
	int		i;
	t_node	node;

	node = (t_node){0,0};
	if (s[0] && (s[1] == '"' || s[1] == '\''))
		;
	else if (*s)
		node.content = ft_strdup(s);
	else if (v)
		node.content = ft_strdup(v);
}

/*
**	If
**	If -s, stop parsing. If not end of arg, digest remainder as string.
*/

static void	get_option(t_option *o, char *s, char *v)
{
	char	*marker;


	while (*s)
	{
		if (*s == 's')
			return get_string(o, &s[1], v);
		else if (*s == 'p')
			o->p = 1;
		else if (*s == 'q' && !(o->r = 0))
			o->q = 1;
		else if (!o->q && *s == 'r')
			o->r = 1;
		else if (*s == 't')
			o->t = 1;
		else if (*s == 'x')
			o->x = 1;
		s++;
	}
}

t_option	parse_option(int n, char **v)
{
	int			i;
	t_option	o;

	i = 0;
	o = (t_option){0, 0, 0, 0, 0, 0};
	while (++i < n)
	{
		if (v[i][0] == '-' && v[i][1] == '-')
			break ;
		else if (v[i][0] == '-' && v[i][1])
			get_option(&o, &v[i][1], v[i + 1]);
	}
	return (o);
}
