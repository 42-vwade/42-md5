/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_utf8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 08:19:37 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	utf[6] = 0;
}

static FT_STR
	parse_utf8(unsigned wc, char **new)
{
	ft_bzero(new[0], 7);
	if (wc < 0x80)
		new[0][0] = wc;
	else
		encode((unsigned char*)new[0], wc);
	return (new[0]);
}

/*
**	Unicode integer string (unsigned int *) as input.
**	Returns UTF-8 encoded characters as a continuous string of bytes.
*/

FT_STR
	encode_utf8_w(int *wc, size_t bytes)
{
	void	*utf;
	char	*chr;

	utf = NULL;
	chr = (char[7]){0, 0, 0, 0, 0, 0, 0};
	while (wc[0] && ((signed)(bytes - ft_strlen(utf) -
				ft_strlen(chr = parse_utf8((wc++)[0], &chr)) > 0)))
		utf = ft_append(utf, chr, 1);
	return (utf);
}

FT_STR
	encode_utf8(int *wc)
{
	void	*utf;
	char	*chr;

	utf = NULL;
	chr = (char[7]){0, 0, 0, 0, 0, 0, 0};
	while (wc[0])
		utf = ft_append(utf, parse_utf8(*wc++, &chr), 1);
	return (utf);
}
