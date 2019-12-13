/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 07:20:06 by viwade            #+#    #+#             */
/*   Updated: 2019/12/13 04:10:09 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int
	ft_ssl(t_config *config)
{
	ft_strlowercase(ft_strncpy(config->verb, config->argv[1], 32));
	ssl_mode(config);
	if (config->mode)
		return (config->mode(config));
	return (config->errno);
}

/*
**	First, check stdin for input. Identify piping method exact. > ssl_config();
**	Second, check if input is a file. Typical behavior.
**	Lastly, check flags for an order of operations. And strings.
*/
