/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 20:10:20 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strnstr(const char *s, const char *c, size_t slen)
{
	unsigned long long int		i;
	size_t						len;

	i = 0;
	len = ft_strlen(&c[0]);
	while (*s && len && slen-- > len - 1)
		if (*s++ == *c)
			if (!ft_strncmp(s, &c[1], len - 1))
				return ((char *)--s);
	return ((len > slen || c[0]) ? NULL : (char *)s);
}
