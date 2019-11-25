/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_infinite_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:41:29 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define NXT_DEC(n) (((n) - (LL)(n)) * 10)
#define NXT_N(n) (n = NXT_DEC(n))
#define ROUND_U(a, b) ((a) >= 5 ? ((b) + 1) : (b))

static char
	*round_inf(char *s, char n)
{
	size_t	len;

	if (n < 5)
		return (s);
	len = ft_strlen(s);
	while (s < &s[len--])
		if (s[len] - 48 == 9)
			s[len] = 48;
		else
			break ;
	s[len] += 1;
	return (s);
}

static char
	*get_decimal(
		ld_t n,
		size_t p)
{
	char	*dec;
	char	buf[2];
	size_t	i;

	i = 0;
	buf[1] = 0;
	while (n >= 1.0)
		n = (n - (LL)n);
	n = (n - (LL)n) * 10;
	dec = ft_memset(ft_strnew(p), 0, p);
	while (i < p)
	{
		if ((LL)n)
			ft_strcat(&dec[i], (char[2]){(LL)n + 48, 0});
		else
			ft_strcat(&dec[i], (char[2]){48, 0});
		n = (n - (LL)n) * 10;
		i += 1;
	}
	round_inf(dec, n);
	return (dec);
}

FT_SIZE
	write_infinite_double(
		ld_t d,
		ull_t p)
{
	FT_NBR	nbr;

	nbr.d = infinite_double(d, p);
	nbr.length = write(1, nbr.d, ft_strlen(nbr.d));
	free(nbr.d);
	return (nbr.length);
}

FT_STR
	infinite_double(
		ld_t n,
		ull_t p)
{
	char	*dec;
	FT_NBR	nbr[1];

	dec = p ? get_decimal(ABS(n), p) : NULL;
	n += dec && (dec[0] == '0' && (char)NXT_DEC(n) == 9);
	nbr[0].d = ft_itoa((LL)n);
	if (p)
		nbr[0].d = ft_strjoin_free(
				nbr[0].d,
				ft_strjoin_free(
					ft_strdup("."),
					dec));
	return (nbr[0].d);
}

FT_STR
	infinite_int(ll_t n)
{
	char	*nbr;
	char	*tmp;

	tmp = NULL;
	nbr = ft_strdup("");
	if (n < 0 ? (n = ABS(n)) : 0)
		nbr = ft_strjoin_free(ft_strdup("-"), nbr);
	if (n >= 10 && (tmp = infinite_int(n / 10)))
		nbr = ft_strjoin_free(tmp, (char[2]){n % 10 + 48, 0});
	if (tmp)
		free(tmp);
	return (nbr);
}
