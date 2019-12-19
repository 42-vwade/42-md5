/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:57:36 by viwade            #+#    #+#             */
/*   Updated: 2019/12/19 14:36:34 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

static long
	openfd_slen(const char *s)
{
	const char *e;

	e = s;
	while (*(e += !!e[0]))
		;
	return (e - s);
}

int
	open_fd(char *fn)
{
	int		fd;

	if (!fn)
		return (0);
	if ((fd = open(fn, O_RDONLY)) < 0)
	{
		write(1, "ft_ssl: ", 8);
		write(1, fn, openfd_slen(fn));
		write(1, ": ", 2);
		write(1, strerror(errno), openfd_slen(strerror(errno)));
		write(1, "\n", 1);
	}
	else
		write(1, "Open success!\n", 14);
	return (fd);
}
