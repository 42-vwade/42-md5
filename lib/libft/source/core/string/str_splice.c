/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_splice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 03:28:53 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Splice string at address.
**	If invalid input, or if address out of bounds, return NULL.
**	If unable to splice string at address, return NULL.
**	On success, value will contain two strings followed by a NULL pointer.
*/

char
	**str_splice(const char *src, void *addr)
{
	const char	*e;
	char		**new;

	if (!src || !addr || addr > (void*)(e = src + ft_strlen(src)))
		return (NULL);
	if (!(new = (char**)malloc(3)))
		return (NULL);
	return (new);
}
