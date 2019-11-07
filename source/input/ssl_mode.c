/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 08:10:54 by viwade            #+#    #+#             */
/*   Updated: 2019/11/07 14:29:07 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_global.h"

void	ssl_mode(t_config *config)
{
	int		i;

	i = 0;
	while (++i < MODE_SELECT || (i = UNDEFINED))
		if (ft_strequ(config->verb, g_jumptable[i].mode))
			break;
	config->mode = g_jumptable[i].func;
	if (!config->mode && (config->error = mode_undefined || 1))
		ssl_error(config);
}
