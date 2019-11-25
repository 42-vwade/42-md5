/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 03:44:09 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*
**	Function searches through string for character given.
**	If found, returns address value at location found.
**	Otherwise, return null.
*/

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		ft_error("");
	while (s[i])
	{
		ptr = (char *)&s[i];
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	return ((s[i] == (char)c) ? (char *)&s[i] : NULL);
}
