/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slen.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 02:48:54 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	slen(const char *s, size_t maxsize)
{
	char *e;

	if (!s)
		return (0);
	e = (char *)s;
	while (maxsize-- && *(e += !!e[0]))
		;
	return (e - s);
}
