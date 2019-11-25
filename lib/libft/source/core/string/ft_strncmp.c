/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 23:49:16 by viwade            #+#    #+#             */
/*   Updated: 2018/11/13 16:29:35 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int
	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	if (!n)
		return (0);
	while (n--)
		if (s1[i] != s2[i])
			break ;
		else if (!s1[i] && !s2[i])
			return (0);
		else if (!s1[i] || !s2[i])
			break ;
		else if (!n)
			return (0);
		else
			i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
