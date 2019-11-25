/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:27:43 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Swaps two bytes in memory.
*/

void
	ft_memswap(const void *a, const void *b)
{
	char	tmp;

	tmp = ((char*)a)[0];
	((char*)a)[0] = ((char*)b)[0];
	((char*)b)[0] = tmp;
}
