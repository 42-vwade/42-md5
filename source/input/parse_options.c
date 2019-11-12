/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:18:05 by viwade            #+#    #+#             */
/*   Updated: 2019/11/12 15:00:34 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int	get_string(t_config *config, char *s, char *v)
{
	t_object	obj;

	ft_bzero(&obj, sizeof(obj));
	if (*s)
		obj.data = s;
	else if (v)
		obj.data = v;
	if (!v && (config->error = no_param))
		return (ssl_error(config));
	obj.type = string;
	obj.length = ft_strlen(obj.data);
	obj.type = string;
	obj.free = 0;
	md5(config);
	return (!*s);
}

/*
**	If
**	If -s, stop parsing. If not end of arg, digest remainder as string.
*/

static int	get_option(t_config *config, char *s, char *v)
{
	char	*marker;


	while (s[0])
	{
		if (s[0] == 's' && ((s[1] && (config->option.s = &s[1])) ||
				(config->option.s = v)))
			return (get_string(config, &s[1], v));
		else if (s[0] == 'p')
			config->option.p = 1;
		else if (s[0] == 'q' && !(config->option.r = 0))
			config->option.q = 1;
		else if (!config->option.q && s[0] == 'r')
			config->option.r = 1;
		else if (s[0] == 't')
			config->option.t = 1;
		else if (s[0] == 'x')
			config->option.x = 1;
		s++;
	}
	return (0);
}

static void	print_option(t_option *o)
{
	ft_printf(
		"flag: s: %s\n"
		"flag: p: %i\n"
		"flag: q: %i\n"
		"flag: r: %i\n"
		"flag: t: %i\n"
		"flag: x: %i\n",
		o->s, o->p, o->q ,o->r ,o->t ,o->x
	);
}

void	parse_option(t_config *config)
{
	int			i;

	ft_bzero(&config->option, sizeof(t_option));
	config->option.queue = &config->queue;
	i = 0;
	while (++i < config->argc)
	{	//	CONFIGURE OPTIONS
		if (config->argv[i][0] == '-' && config->argv[i][1] == '-')
			break ;
		else if (config->argv[i][0] == '-' && (
			config->option.s = ft_strchr(&config->argv[i][1], 's')) && ((
			config->option.s[1] && (config->option.s = &config->option.s[1])) ||
			((i + 1 < config->argc) && (config->option.s = config->argv[i + 1]))
		))
			;
		else if (config->argv[i][0] == '-' && config->argv[i][1])
			i += get_option(config, &config->argv[i][1],
				i + 1 < config->argc ? config->argv[i + 1] : 0);
	}	//	POST-CONFIGURATION
	//	BEGIN DECIPHER
	print_option(&config->option);
	exit(2);
}
