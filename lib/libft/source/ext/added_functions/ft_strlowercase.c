/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize copy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:25:30 by viwade            #+#    #+#             */
/*   Updated: 2019/11/07 09:02:26 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void
	down_case(char *c)
{
	c[0] += ('A' <= c[0] && c[0] <= 'Z') ? 32 : 0;
}

char
	*ft_strlowercase(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		down_case(&s[i++]);
	return (s);
}
