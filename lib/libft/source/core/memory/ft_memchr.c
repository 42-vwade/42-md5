/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 03:44:09 by viwade            #+#    #+#             */
/*   Updated: 2019/05/31 13:21:14 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#define BREAK

/*
**	Search function.
**	Function searches for a given value through n bytes of memory.
**	If found, the address where the value is located is returned.
**	If it is not found, NULL is returned.
*/

void
	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	while (n--)
	{
		p = &((unsigned char *)s)[i];
		if ((unsigned char)c == p[0])
			return ((void *)p);
		i++;
	}
	return (NULL);
}
