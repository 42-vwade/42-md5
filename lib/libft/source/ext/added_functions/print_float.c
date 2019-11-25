/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:02:58 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define SIGN(n) ((n) & 0x01 << 31)
#define EXPO(n) ((n) & 0x0FFFF)

void	print_float(float f, size_t precision)
{
	uint32_t	data;

	ft_memcpy(&data, &f, sizeof(f));
	print_memory(&f, sizeof(f));
	print_memory(&data, sizeof(data));
	if (precision)
		data = 0;
}
