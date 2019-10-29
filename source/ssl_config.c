/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:10:41 by viwade            #+#    #+#             */
/*   Updated: 2019/10/23 12:53:15 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void
	config_init(t_config *config, int argc, char **argv)
{
	ft_bzero(config, sizeof(*config));
	config->argc = argc;
	config->argv = argv;
	config->prgnm = ft_basename(argv[0]);
}

int	ssl_config(int n, char **v)
{
	t_config	config;

	config_init(&config, n, v);
	if (!(config.mode))
		ssl_error(&config);
	return (config.mode(&config));
}
