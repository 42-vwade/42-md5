/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delimit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 09:46:53 by viwade            #+#    #+#             */
/*   Updated: 2019/11/11 11:36:48 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void
	do_delimit(const char **s, long long *trim)
{
	const char	*tmp;

	tmp = ft_strsub(s[0], 1, trim[0] - 1);
	ft_memdel((void **)s);
	s[0] = tmp;
	trim[0] -= 2;
}

/*
**	Trims a string on both ends by removing pairs of delimiters.
**	Modifies the string directly.
**	Frees and allocates memory.
**	If string length is less than 1, nothing is done.
*/

void
	ft_delimit(const char **s, int c)
{
	long long	trim;

	if (!s || !s[0] || !(s[0][0] && s[0][1]))
		return ;
	if (!(s[0][0] == c && c == s[0][trim = ft_strlen(s[0]) - 1]))
		return ;
	else
		while (trim > 0 && (s[0][0] == c && c == s[0][trim]))
			do_delimit(s, &trim);
}
