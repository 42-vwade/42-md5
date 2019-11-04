/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:14:33 by viwade            #+#    #+#             */
/*   Updated: 2019/11/01 17:23:04 by viwade           ###   ########.fr       */
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

static void
	md5_readin(t_md5 *md5)
{
	int		nb;

	ft_bzero(md5->message, sizeof(md5->message));
	if ((nb = read(md5->object->fd, md5->message, 64)) < 64)
	{
		if (nb < 56)
		{
			((char *)md5->message)[nb] = 0x80;
			ft_memset(&((char *)md5->message)[nb + 1], 0, 56 - nb);
			md5->length += nb * 8;
			ft_memcpy(&md5->message[14], &md5->length, sizeof(md5->length));
		}
		else
		{
			((char *)md5->message)[nb] = 0x80;
			ft_memset(&((char *)md5->message)[nb + 1], 0, 64 - nb);
		}
	}
	else
		md5->length += nb * 8;
}

static void
	md5_pad(t_queue *o, t_digest *m)
{}

static void
	md5_string(t_md5 *md5)
{
	size_t	len;
	void	*start;

	ft_bzero(md5->block, sizeof(md5->block));
	len = ft_strlen(md5->object->data);
	ft_memcpy(&md5->block[56], &(unsigned long){len * 8}, sizeof(long));
	md5->block[len % 64 % 56] = 0x80;
	start = ((char*)md5->object->data)[len - (len % 64 % 56)];
	ft_memcpy(md5->block, start, len % 64 % 56);
	return ;
	ft_memcpy(&md5->block[56 - (len % 64 % 56)], &(long){len * 8}, sizeof(len));
}

static int
	mds_alorithm(t_md5 *md5)
{
	unsigned int	f;
	unsigned int	g;

	md5->i = 0;
	md5->a = md5->state.a;
	md5->b = md5->state.b;
	md5->c = md5->state.c;
	md5->d = md5->state.d;
	while (md5->i < 64)
	{
		if (md5->i < 16 && ((f = F(md5->b, md5->c, md5->d)) || 1))
			g = md5->i;
		else if (md5->i < 32 && ((f = G(md5->b, md5->c, md5->d)) || 1))
			g = (5 * md5->i + 1) % 16;
		else if (md5->i < 48 && ((f = H(md5->b, md5->c, md5->d)) || 1))
			g = (3 * md5->i + 5) % 16;
		else if (md5->i < 64 && ((f = I(md5->b, md5->c, md5->d)) || 1))
			g = (7 * md5->i) % 16;
		f = f + md5->a + g_key[md5->i] + md5->message[g];
		md5->a = md5->d;
		md5->d = md5->c;
		md5->c = md5->b;
		md5->b = md5->b + R(f, g_md5_shift[((md5->i / 16) * 4) + (md5->i % 4)]);
		md5->i++;
	}
	md5->state = (t_state){md5->state.a + md5->a, md5->state.b + md5->b, 
		md5->state.c + md5->c, md5->state.d + md5->d};
}

int
	md5(t_config *o)
{
	t_md5	md5;
	t_node	*node;

	md5.state = (t_state){A, B, C, D};
	node = o->queue.next;
	while (node)
	{
		md5.object = node->content;
		if (md5.object->type == file)
			md5_readin(&md5);
		node = node->next;
	}
	print_hex(md5.state.a);
	print_hex(md5.state.b);
	print_hex(md5.state.c);
	print_hex(md5.state.d);
	return (0);
}
