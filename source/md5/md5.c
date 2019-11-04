/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:14:33 by viwade            #+#    #+#             */
/*   Updated: 2019/11/04 00:50:52 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

int		g_md5_shift[16] = {
	7, 12, 17, 22,
	5, 9, 14, 20,
	4, 11, 16, 23,
	6, 10, 15, 21
};
char	g_md5_pad[64] = {
	0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0
};
int		g_key[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

static int
	mds_alorithm(t_md5 *md5)
{
	md5->i = 0;
	md5->a = md5->result[0];
	md5->b = md5->result[1];
	md5->c = md5->result[2];
	md5->d = md5->result[3];
	while (md5->i < 64)
	{
		if (md5->i < 16 && ((md5->f = F(md5->b, md5->c, md5->d)) || 1))
			md5->g = md5->i;
		else if (md5->i < 32 && ((md5->f = G(md5->b, md5->c, md5->d)) || 1))
			md5->g = (5 * md5->i + 1) % 16;
		else if (md5->i < 48 && ((md5->f = H(md5->b, md5->c, md5->d)) || 1))
			md5->g = (3 * md5->i + 5) % 16;
		else if (md5->i < 64 && ((md5->f = I(md5->b, md5->c, md5->d)) || 1))
			md5->g = (7 * md5->i) % 16;
		md5->f = md5->f + md5->a + g_key[md5->i] + md5->message[md5->g];
		S(md5->a, md5->b, md5->c, md5->d);
		md5->b += R(md5->f, g_md5_shift[((md5->i / 16) * 4) + (md5->i % 4)]);
		md5->i++;
	}
	md5->result[0] += md5->a;
	md5->result[1] += md5->b;
	md5->result[2] += md5->c;
	md5->result[3] += md5->d;
}

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
		ft_memset(&((char *)md5->message)[md5->nb + 1], 0, 64 - md5->nb);
		md5_algorithm(md5);
		ft_memset(&((char *)md5->message)[0], 0, 56);
		ft_memcpy(&((char *)md5->message)[56], &md5->length, 8);
		md5_algorithm(md5);
	}
	else
		md5_algorithm(md5);
}

static void
	md5_readin(t_md5 *md5)
{
	while ((md5->nb = read(md5->object->fd, md5->message, 64)) > -1)
	{
		md5->length += md5->nb * 8;
		md5_message(md5);
		if (!md5->nb)
			break;
	}
	if (md5->nb == -1)
		md5_error();
}

static void
	md5_string(t_md5 *md5)
{
	md5->len = ft_strlen(md5->object->data);
	md5->length = md5->len * 8;
	while (md5->object->data < &md5->object->data[md5->len])
	{
		md5->nb = &md5->object->data[md5->len] - md5->object->data;
		if (md5->nb < 64)
		{
			ft_memcpy(md5->message, md5->object->data, md5->nb);
			md5->object->data += md5->nb;
		}
		else
		{
			ft_memcpy(md5->message, md5->object->data, 64);
			md5->object->data += 64;
		}
		md5_message(md5);
	}
}


int
	md5(t_config *o)
{
	t_md5	md5;
	t_node	*node;

	ft_bzero(&md5, sizeof(md5));
	md5.result[0] = A;
	md5.result[1] = B;
	md5.result[2] = C;
	md5.result[3] = D;
	node = o->queue.next;
	while (node)
	{
		md5.object = node->content;
		if (md5.object->type == file && ((md5.fd = md5.object->fd) || 1))
			md5_readin(&md5);
		else if (md5.object->type == string)
			md5_string(&md5);
		node = node->next;
	}
	return (md5.ret);
}
