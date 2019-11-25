/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 02:48:54 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
**	Returns number of integers in a string of integers.
**	Integer string shall be null-terminated.
*/

size_t	ft_lstrlen(const wchar_t *s)
{
	const char	*e;

	e = (const char *)s;
	while (e[0] + e[1] + e[2] + e[3])
		e += 4;
	return ((e - (const char*)s) / sizeof(int));
}
