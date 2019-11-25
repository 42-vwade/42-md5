/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 04:09:54 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long
	*ft_strtol(char *s)
{
	uint64_t	*new;
	size_t		i;

	if (!s || !(new = (uint64_t*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i++])
		new[i - 1] = (unsigned long long)s[i - 1];
	return (new);
}
