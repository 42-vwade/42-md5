/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:25:30 by viwade            #+#    #+#             */
/*   Updated: 2019/05/13 17:33:39 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void
	up_case(char *c)
{
	c[0] -= ('a' <= c[0] && c[0] <= 'z') * 32;
}

char
	*ft_strcapitalize(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		up_case(&s[i++]);
	return (s);
}
