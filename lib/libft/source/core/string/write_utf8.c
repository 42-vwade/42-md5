/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utf8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:10:43 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:54:12 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
**	Unicode integer (unsigned) as input.
**	Writes to the standard output.
*/\

size_t
	write_utf8(unsigned int wc)
{
	return (write_utf8_fd(wc, 1));
}
