/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:02:18 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	HEXADECIMAL TO LONG
*/

static char
	hex_value(char c)
{
	if (48 <= c && c <= 57)
		return (c - 48);
	else if ((97 <= c && c <= 102) || (65 <= c && c <= 70))
		return (c - (55 + 32 * (97 <= c && c <= 102)));
	else
		return (-1);
}

unsigned long long
	ft_hextol(char *s)
{
	unsigned long long	num;
	char				val;

	num = 0;
	while ((val = ((9 <= s[0] && s[0] <= 13) || s[0] == 32)))
		s++;
	s += 2 * ((s[0] == '0' || s[0] == '\\') && (s[0] && s[1] == 'x'));
	s += (s[0] == '#');
	while ((val = hex_value((s++)[0])) > -1)
		num = num * 16 + val;
	return (num);
}

unsigned long long
	ft_octtol(char *s)
{
	unsigned long long	num;
	char				val;

	num = 0;
	while ((val = ((9 <= s[0] && s[0] <= 13) || s[0] == 32)))
		s++;
	s += (s[0] == '0' && (s[0] && ('1' <= s[1] && s[1] <= '8')));
	while (('0' <= s[0] && s[0] <= '8'))
		num = num * 8 + val;
	return (num);
}
