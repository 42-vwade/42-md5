/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utf8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:10:43 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
**	Unicode string as array of integer-32 values.
**	Unicode string shall be null-terminated.
*/

size_t
	print_utf8(unsigned int *ws)
{
	size_t	size;

	size = 0;
	if (ws)
		while (ws[0])
			size += write_utf8((ws++)[0]);
	return (size);
}
