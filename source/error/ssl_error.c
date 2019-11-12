/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:53:44 by viwade            #+#    #+#             */
/*   Updated: 2019/11/12 13:45:18 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int
	ssl_error(t_config *config)
{
	if (config->error == no_param && !(config->errno = 0))
		ft_printf("%s: insufficient input parameters.\n", config->prgnm);;
	if (config->error == mode_undefined && !(config->errno = 0))
		ft_printf("%s: '%s' is an invalid command.\n",
			config->prgnm, config->argv[2]);
	ssl_usage(config);
	exit(config->errno);
}