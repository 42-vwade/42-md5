/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:04:44 by viwade            #+#    #+#             */
/*   Updated: 2019/10/22 08:44:04 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_basename(char *path)
{
	long	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	while (path < &path[len])
		if (path[--len] == '/')
			return (&path[++len]);
	return (path);
}
