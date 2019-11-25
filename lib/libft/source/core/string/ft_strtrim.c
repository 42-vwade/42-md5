/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 09:46:53 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;
	char	*new;

	if (!s)
		return (NULL);
	start = 0;
	len = ft_strlen(s);
	while (is_whitespace(s[start]))
		start++;
	if (len)
		while (is_whitespace(s[len - 1]) && (start < len))
			len--;
	if (start <= len)
		if ((new = ft_strsub(s, start, len - start)))
			return (new);
	return (NULL);
}
