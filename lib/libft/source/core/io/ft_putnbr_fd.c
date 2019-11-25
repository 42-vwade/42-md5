/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 19:25:34 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void
	ft_putnbr_fd(long long int n, int fd)
{
	long	len;
	long	tmp;
	char	c;

	tmp = n;
	len = 1;
	if (n < 0)
		write(fd, "-", 1);
	while (tmp /= 10)
		len *= 10;
	while (len)
	{
		c = ABS(n) / len + 48;
		write(fd, &c, 1);
		n %= len;
		len /= 10;
	}
}
