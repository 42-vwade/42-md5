/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 04:02:56 by viwade            #+#    #+#             */
/*   Updated: 2018/11/09 21:09:39 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	while (i++ < n)
	{
		p1 = &((unsigned char *)s1)[i - 1];
		p2 = &((unsigned char *)s2)[i - 1];
		if (p1[0] != p2[0])
			return (p1[0] - p2[0]);
	}
	return (0);
}
