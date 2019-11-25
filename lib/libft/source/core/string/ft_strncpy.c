/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:46:08 by viwade            #+#    #+#             */
/*   Updated: 2019/11/07 09:46:37 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		ft_error("");
	while (n && (dst[i] = src[i]))
		if (n--)
			i++;
	if (n > 0)
		ft_bzero(&dst[i], n);
	return (dst);
}
