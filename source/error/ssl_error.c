/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:53:44 by viwade            #+#    #+#             */
/*   Updated: 2019/11/03 19:57:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void
	ssl_usage(void)
{
	char	*usage;

	usage =
		"Message Digest Commands\n"
		"md5\n\n"

	;
	write(1, usage, ft_strlen(usage));
}

void
	ssl_error(config)
t_config *config;
{
	ft_printf("%s: '%s' is an invalid command.\n", config->prgnm,
		config->argv[1]);
	ssl_usage();
}