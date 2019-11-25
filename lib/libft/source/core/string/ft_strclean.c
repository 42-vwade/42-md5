/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 09:46:53 by viwade            #+#    #+#             */
/*   Updated: 2019/11/11 10:08:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define FT_CMP(a,b)	((a)==(b))

static void
	delimit_c(const char **src, char c)
{
	const char	*s;
	const char	*e;

	s = src[0];
	e = s;
	while (*(e += !!e[0]))
		;
	while (*s == c)
		s += 1;
	while (s < e && *e == c)
		e -= 1;
	if (s <= e)
		src[0] = ft_strsub(s, 0, e - s);
}

char
	*ft_strclean(const char *s, char c)
{
	if (!s)
		return (NULL);
	s = ft_strtrim(s);
	if (c)
		delimit_c(&s, c);
	return ((char *)s);
}

/*
**	Takes a string and cleans it.
**	Removes whitespace from ends, as well as any delimiters (c) left over.
*/
