/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 00:15:55 by viwade            #+#    #+#             */
/*   Updated: 2019/07/17 22:20:22 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _FT_SQRT	long double ft_sqroot(long double n){return(ft_sqrt(n));}

long double
	ft_sqrt(long double n)
{
	long double		c;
	long double		i;
	unsigned char	ii;

	i = 1;
	c = 0;
	if (n < 0)
		return (0.0);
	if (!n)
		return (0.0);
	while (c * c != n && i > 1e-19 && (ii = 9))
	{
		while ((c + i) * (c + i) <= n && ii--)
			c += i;
		i /= 10.0;
	}
	return (c);
}

_FT_SQRT;
