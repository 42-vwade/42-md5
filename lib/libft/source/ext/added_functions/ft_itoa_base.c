/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:58:04 by viwade            #+#    #+#             */
/*   Updated: 2019/12/30 08:52:52 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#define BASE16_LOWER "0123456789abcdef"
#define BASE16_UPPER "0123456789ABCDEF"
#define FT_ITOA_SIZE(x)
#define FT_ITOA_PUT(k,n,b,a) (a) = (k)[ABS(n) % b]; n /= b

/*
**	static void
**		recurse(int n, char *s, unsigned long long value)
**	{
**		if (n)
**			recurse(n - 1, s, value / 10);
**		s[n] = value % 10;
**	}
*/

static long
	abs(long n)
{
	return (n < 0 ? -(n) : (n));
}

char	*ft_itoa_base(unsigned long long n, int base)
{
	size_t		len;
	uint64_t	tmp;
	uint8_t		size;
	char		*str;
	char		*key;

	len = 0;
	key = BASE16_LOWER;
	size = (n * (base == 10)) + 2;
	tmp = n;
	while (tmp /= base)
		len++;
	len += size;
	if ((str = (char *)malloc(len * sizeof(*str))))
	{
		str[--len] = 0;
		while (len--)
		{
			str[len] = key[abs(n) % base];
			n /= base;
		}
		if (size == 3)
			str[0] = '-';
	}
	return (str);
}
