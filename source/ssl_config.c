/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:10:41 by viwade            #+#    #+#             */
/*   Updated: 2019/11/12 15:56:04 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ssl_config(t_config *config)
{
	ft_printf(
		"%s: You have reached the configuration function.\
		Display plans? [y/n]\n", config->prgnm); exit(1);
	//parse_options(config);
}
