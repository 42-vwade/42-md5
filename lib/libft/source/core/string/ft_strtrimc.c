/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 09:46:53 by viwade            #+#    #+#             */
/*   Updated: 2019/11/11 09:53:16 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define IS_DELIM(a,b)	((a)==(b))

char		*ft_strtrimc(char const *s, char c)
{
	size_t	start;
	size_t	len;
	char	*new;

	if (!s || !c)
		return (NULL);
	start = 0;
	len = ft_strlen(s);
	while (IS_DELIM(s[start], c))
		start++;
	if (len)
		while (IS_DELIM(s[len - 1], c) && (start < len))
			len--;
	if (start <= len)
		if ((new = ft_strsub(s, start, len - start)))
			return (new);
	return (NULL);
}
