/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:10:10 by viwade            #+#    #+#             */
/*   Updated: 2019/11/18 20:35:57 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

static t_bool
	parse_args(int n, char **v, t_option *o, int *i)
{
	t_bool	ok = 0;

	i[0] = 1;
	ft_bzero(o, sizeof(*o));
	while ((i[0] += 1) < n)
	{
		if ((v[*i][0] == '-' && v[*i][1] == '-') || !(ok = 1))
			break;
		{}
	}
	return (ok);
}

t_bool
	md5_configure(int n, char **v, t_config *config)
{
	int		i;
	t_bool	ok = 0;

	parse_args(n, v, &config->option, &i);
	return (ok);
}
