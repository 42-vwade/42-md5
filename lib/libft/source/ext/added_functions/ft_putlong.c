/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 08:55:29 by viwade            #+#    #+#             */
/*   Updated: 2019/02/08 18:06:28 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define ABS(x) (((x) < 0) ? -(x) : (x))

void
	ft_putlong(long n)
{
	int		fd;
	long	len;
	long	tmp;
	char	c;

	fd = 1;
	tmp = n;
	len = 1;
	if (n < 0)
		write(fd, "-", 1);
	while (tmp /= 10)
		len *= 10;
	while (len)
	{
		c = (char)((n < 0) ? -(n / len) : n / len) + 48;
		write(fd, &c, 1);
		n %= len;
		len /= 10;
	}
}
