/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:53:44 by viwade            #+#    #+#             */
/*   Updated: 2019/10/23 12:57:23 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void
	ssl_usage(void)
{

}

void
	ssl_error(config)
t_config *config;
{
	ft_printf("%s: '%s' is an invalid command.\n", config->prgnm,
		config->argv[1]);
	ssl_usage();
}