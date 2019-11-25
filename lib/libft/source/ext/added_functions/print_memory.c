/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:50:30 by viwade            #+#    #+#             */
/*   Updated: 2019/11/25 09:21:56 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
**	static void
**		print_hex(unsigned char c)
**	{
**		char	*key;
**
**		key = "0123456789abcdef";
**		write(1, (char[2]){key[c >> 4], key[c & 0x0f]}, 2);
**	}
*/

static void
	put_hex(int i, size_t size, const char *addr)
{
	size_t	j;

	j = 0;
	while (j < 16)
	{
		if (i + j < size)
			print_hex((uint8_t)addr[i + j]);
		else
			write(1, "  ", 2);
		if (j % 2)
			write(1, " ", 1);
		++j;
	}
}

static void
	put_str(int i, size_t size, const char *addr)
{
	size_t	j;

	j = 0;
	while (j < 16 && i + j < size)
	{
		if (ft_isprint(addr[i + j]))
			write(1, &addr[i + j], 1);
		else
			write(1, ".", 1);
		++j;
	}
}

void
	print_memory(const void *addr, size_t size)
{
	size_t	i;

	if (!addr)
		return ;
	i = 0;
	while (i < size)
	{
		put_hex(i, size, (const char *)addr);
		put_str(i, size, (const char *)addr);
		write(1, "\n", 1);
		i += 16;
	}
}
