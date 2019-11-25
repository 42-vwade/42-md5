/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 20:10:20 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	compare_str(const char *s, const char *q)
{
	size_t	i;

	i = 0;
	while (s[i] == q[i])
		if (!q[++i])
			return (1);
	return (0);
}

char		*ft_strstr(const char *s, const char *c)
{
	size_t	i;

	i = 0;
	if (!s || !c)
		ft_error("");
	while (s[i])
		if (s[i++] == c[0])
			if (compare_str(&s[i - 1], c))
				return ((char *)&s[i - 1]);
	return ((c[0]) ? NULL : (char *)s);
}
