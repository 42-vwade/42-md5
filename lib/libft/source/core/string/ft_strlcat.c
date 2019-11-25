/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:38:07 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	size_t	len;

	i = 0;
	if (!dst || !src)
		ft_error("");
	if (!dstsize || (dstsize <= (len = ft_strlen(dst))))
		return (ft_strlen(src) + dstsize);
	n = dstsize - len - 1;
	while ((dst[len + i] = src[i]) && n--)
		i++;
	dst[len + i] = 0;
	return (len + ft_strlen(src));
}
