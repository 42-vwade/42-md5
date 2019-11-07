/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:18:14 by viwade            #+#    #+#             */
/*   Updated: 2019/11/07 12:46:46 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void
	ssl_usage(t_config *config)
{
	char	*usage;

	write(1, "usage: ", 7);
	ft_putstr(ft_basename(config->prgnm));
	usage = "command [command_options] [command_args]\n"
		"\n"
		"Message Digest Commands\n"
		"md5\t""sha256\n\n"
	;
	write(1, usage, 92);
}
