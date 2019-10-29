/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:16:15 by viwade            #+#    #+#             */
/*   Updated: 2019/10/21 22:25:35 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_global.h"

static int
	ssl_usage(char *prgnm)
{
	char	*usage;

	write(1, "usage: ", 7);
	ft_putstr(prgnm);
	usage = "command [command_options] [command_args]\n"
		"options: usage:"
	;
	write(1, usage, 0);
	return (0);
}

static int
	ssl_mode(char *v1)
{
	int		i;

	i = 0;
	while (g_jumptable[i].func)
		if (ft_strequ(g_jumptable[i].func, v1))
			return (i);
		else
			i++;
}

int
	main(int argc, char **argv)
{
	if (argc > 2)
		return (ssl_config(argc, argv));
	else
		return (ssl_usage(argv[0]));
}

/*
**	RETURN VALUES
**	0	-	Normal.
**	1	-	Unknown option '%c'
*/
