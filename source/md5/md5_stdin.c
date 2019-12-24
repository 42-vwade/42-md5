/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:53:56 by viwade            #+#    #+#             */
/*   Updated: 2019/12/24 02:13:04 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"
#define BUF	(1024 * 1024 / sizeof(char))

void
	md5_stdin(t_md5 *md5)
{
	char	*line;
	char	buf[BUF + 1];
	int		nb;

	if ((line = (void*)(long)(md5->object.fd == -1)))
		return ;
	while ((nb = read(md5->object.fd, buf, BUF)) > 0 &&
			ft_memset(&buf[nb], 0, BUF - nb))
		line = ft_append(line, buf, 1);
	close(md5->object.fd);
	
	md5->object.data = line;
	md5->object.length = ft_strlen(md5->object.data);
	md5_string(md5);
	ft_memdel((void **)&line);
}
