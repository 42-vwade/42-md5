/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 04:19:53 by viwade            #+#    #+#             */
/*   Updated: 2019/12/19 15:50:54 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

static void
	md5_message(t_md5 *md5)
{
	if (md5->nb < 56)
	{	// if fewer than 448 bits have been read
		((char *)md5->message)[md5->nb] = 0x80;
		ft_memset(&((char *)md5->message)[md5->nb + 1], 0, 56 - md5->nb);
		ft_memcpy(&((char *)md5->message)[56], &md5->length, 8);
		md5_algorithm(md5);
	}
	else if (md5->nb < 64)
	{	// if fewer than 512 bits have been read, & more than 448
		((char *)md5->message)[md5->nb] = 0x80;
		ft_memset(&((char *)md5->message)[md5->nb + 1], 0, 64 - (md5->nb + 1));
		md5_algorithm(md5);
		ft_memset(&((char *)md5->message)[0], 0, 56);
		ft_memcpy(&((char *)md5->message)[56], &md5->length, 8);
		md5_algorithm(md5);
	}
	else
		md5_algorithm(md5);
}

static void
	md5_print(t_md5 *md5)
{
	int		i = 0;
	char	hex[32 + 1];

	ft_memset(hex, '-', sizeof(hex) - 1);
	hex[32]	= 0;
	while (i < 32)
	{
		hex[i] = HEXA[0xf & (md5->result[i / 8] >> (4 * ((i + 1) % 8)))];
		hex[i + 1] = HEXA[0xf & (md5->result[i / 8] >> (4 * (i % 8)))];
		i += 2;
	}
	if (md5->option.q)
		ft_printf ("%s\n", hex);
	else if (md5->option.r)
		ft_printf ("%s\n", hex);
	ft_printf("MD5 (\"%s\") = %s\n", md5->object.data, hex);
}

static void
	md5_readin(t_md5 *md5)
{
	while ((md5->nb = read(md5->object.fd, md5->message, 64)) > -1)
	{
		if (md5->option.p)
			write(1, md5->message, md5->nb);
		if (md5->nb < 64)
			ft_bzero(&((char*)md5->message)[md5->nb], 64 - md5->nb);
		md5->length += md5->nb * 8;
		md5_message(md5);
		if (md5->nb < 64)
			break;
	}
	if (md5->nb == -1)
		ft_error("ft_ssl: MD5: read error");
	else
		md5_print(md5);
}

static void
	md5_string(t_md5 *md5)
{
	md5->nb = ft_strlen(md5->object.data);
	md5->length = md5->nb * 8;
	if (!(md5->len = md5->nb))
		md5_message(md5);
	while (md5->nb)
	{
		ft_memcpy(md5->message, &md5->object.data[md5->object.offset], md5->nb
			< 64 ? md5->nb : 64);
		md5->object.offset += md5->nb < 64 ? md5->nb : 64;
		md5_message(md5);
		if ((md5->nb = md5->len - md5->object.offset) == 64)
		{
			ft_memcpy(
				md5->message, &md5->object.data[md5->object.offset], 64);
			md5->object.offset += 64;
			md5_message(md5);
			md5->nb -= 64;
			md5_message(md5);
		}
	}
	md5_print(md5);
}

void
	md5_input(int fd, char *string, t_md5 *md5)
{
	md5->object = (t_object){
		.fd = !fd && string ? open_fd(string) : 0,
		.data = string,
		.length = fd != -1 ? ft_strlen(string) : 0,
		.offset = 0,
		.type = 0,
		.free = 0
	};
	if (string && fd == -1)
		md5_string(md5);
	else
		md5_readin(md5);
}

/*
**	RUNDOWN
**	Available options: p, q, r, s
**	Order of precedence:
**	-	p: Read stdin to stdout, then display stdin hash on output
**		-	Display contents of file (as it is read, presumably)
**		-	If given, an attempt to read stdin must be made before doing
**			anything else.
**	-	q: Quiet mode (Meaning?)
**	-	r: Reverse display. Print md5 hash followed by input string.
**	-	s:
*/
