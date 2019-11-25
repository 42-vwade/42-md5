/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:38:19 by viwade            #+#    #+#             */
/*   Updated: 2019/11/12 14:49:06 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_option(int n, char **v)
{
	static char	args[255];
	int			i;
	int			j;

	i = 0;
	while (++i < n && !(j = 0))
	{
		if (v[i][j] == '-')
			while (v[i][++j])
				if (!args[(int)v[i][j]])
					args[(int)v[i][j]] = v[i][j];
	}
	return (args);
}
