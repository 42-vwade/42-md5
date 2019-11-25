/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utf8_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:10:43 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#define ENC(n) (wc >= (n))
#define ENC1 (ENC(0x80) + ENC(0x800) + ENC(0x10000))
#define ENC2 (ENC(0x200000) + ENC(0x4000000))
#define SET(b) (((n > (b)) | 2) << (6 - (b)))

static uint8_t
	pad(int8_t n)
{
	uint8_t	pad;

	pad = 0xC0;
	while (0 < n--)
		pad = (pad >> 1) + 0x80;
	return (pad);
}

static void
	encode(uint8_t *utf, unsigned wc)
{
	uint8_t	set;
	size_t	n;

	n = 1 + ENC1 + ENC2;
	set = (n - 1) ? pad(n - 1) : 0x80;
	while (n--)
		if (n)
			(utf[n] = 0x80 | (~(0xC0) & wc)) && (wc >>= 6);
		else
			utf[n] = (set << 1) | (~(set) & wc);
}

/*
**	Unicode integer (unsigned) as input.
**	Writes to specified file_descriptor.
*/

size_t
	write_utf8_fd(unsigned int wc, int fd)
{
	uint8_t	utf[7];

	ft_bzero(utf, 7);
	if (!wc)
		return (0);
	else if (wc < 0x80)
		utf[0] = wc;
	else
		encode(utf, wc);
	return (write(fd, utf, ft_strlen((char*)utf)));
}
