/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utf8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 04:09:54 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	*str_utf8(wchar_t *s)
{
	int		*new;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_lstrlen(s) + 1;
	if (!s || !(new = (int*)malloc((len) * sizeof(int))))
		return (NULL);
	while (s[i++] && (len -= !!len))
		new[i - 1] = (int)s[i - 1];
	return (new);
}
