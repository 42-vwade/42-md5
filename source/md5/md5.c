/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:14:33 by viwade            #+#    #+#             */
/*   Updated: 2019/12/13 08:38:32 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

unsigned
	g_md5_shift[16] = {
	7, 12, 17, 22,
	5, 9, 14, 20,
	4, 11, 16, 23,
	6, 10, 15, 21
};

unsigned
	g_md5_key[64] = {
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
	md5_algorithm(t_md5 *md5)
{
	md5->a = md5->result[0];
	md5->b = md5->result[1];
	md5->c = md5->result[2];
	md5->d = md5->result[3];
	while (md5->i < 64 || (md5->i = 0))
	{
		if (ff(md5->i, &md5->f, (int[]){md5->b, md5->c, md5->d}, 70) < 16)
			md5->g = md5->i;
		else if (ff(md5->i, &md5->f, (int[]){md5->b, md5->c, md5->d}, 71) < 32)
			md5->g = (5 * md5->i + 1) % 16;
		else if (ff(md5->i, &md5->f, (int[]){md5->b, md5->c, md5->d}, 72) < 48)
			md5->g = (3 * md5->i + 5) % 16;
		else if (ff(md5->i, &md5->f, (int[]){md5->b, md5->c, md5->d}, 73) < 64)
			md5->g = (7 * md5->i) % 16;
		md5->f = md5->b + m_rr(md5->a + md5->f + g_md5_key[md5->i] +
		md5->message[md5->g], g_md5_shift[((md5->i / 16) * 4) + (md5->i % 4)]);
		m_rotate(&md5->a, &md5->b, &md5->c, &md5->d);
		md5->b = md5->f;
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
	md5_readin(t_md5 *md5)
{
	while ((md5->nb = read(md5->object->fd, md5->message, 64)) != -1)
	{
		if (md5->option.p)
			write(1, md5->message, md5->nb);
		md5->length += md5->nb * 8;
		md5_message(md5);
		if (!md5->nb)
			break;
	}
	if (md5->nb == -1)
		ft_error("ft_ssl: MD5: read error");
}

static void
	md5_string(t_md5 *md5)
{
	md5->nb = ft_strlen(md5->object->data);
	md5->length = md5->nb * 8;
	if (!(md5->len = md5->nb))
		md5_message(md5);
	while (md5->nb)
	{
		ft_memcpy(md5->message, &md5->object->data[md5->object->offset], md5->nb
			< 64 ? md5->nb : 64);
		md5->object->offset += md5->nb < 64 ? md5->nb : 64;
		md5_message(md5);
		if ((md5->nb = md5->len - md5->object->offset) == 64)
		{
			ft_memcpy(
				md5->message, &md5->object->data[md5->object->offset], 64);
			md5->object->offset += 64;
			md5_message(md5);
			md5->nb -= 64;
			md5_message(md5);
		}
	}
}

static void
	md5_print(t_md5 *md5)
{
	int		i = 0;
	char	hex[32 + 1];

	ft_memset(hex, '-', sizeof(hex));
	//print_memory(md5->result, sizeof(md5->result));
	/*return;//*/
	while (i < 32)
	{
		hex[i] = HEXA[0xf & (md5->result[i / 8] >> (4 * ((i + 1) % 8)))];
		hex[i + 1] = HEXA[0xf & (md5->result[i / 8] >> (4 * (i % 8)))];
		// ft_printf("md5_print[%i]: %hhi | %c\t",	i,
		// 	0xf & (md5->result[i / 8] >> (4 * (i % 8))), hex[i]);
		i += 2;
		//(!(i % 2) || 1) && (write(1, hex, i) && write(1, "\n", 1));
	}
	hex[32]	= 0;
	ft_printf("MD5 (\"%s\") = %s\n", md5->object->data, hex);
}

static void
	md5_input(char *string, int fd, t_md5 *md5)
{
	md5->object = (t_object){fd, 0, 0, 0, 0, 0};
	if (string && (md5->object.data = string))
		md5_string(md5);
	else
		md5_readin(md5);
}


int
	md5(t_config *cfg)
{
	size_t	n = 1;
	t_md5	md5;
	t_node	*node;

	ft_bzero(&md5, sizeof(md5));
	ft_memcpy(md5.result, (int[]){A, B, C, D}, sizeof(int[4]));
	if (!(cfg->argc - 2))
		md5_input(0, 0, &md5);
	while (md5_args(cfg->argc + 2, cfg->argv + 2, &md5))
		;
	while (++n < cfg->argc)
		;
/*	md5.result[0] = A;
	md5.result[1] = B;
	md5.result[2] = C;
	md5.result[3] = D;//*/
	{	/*	TEST //	*/
		// t_object test;
		// ft_bzero(&test, sizeof(test));
		// test.data = "";
		// test.fd = 0;
		md5.object = cfg->obj;
		md5_string(&md5);
		md5_readin(&md5);
		md5_print(&md5);
		return (md5.ret);	}//*/
/*	node = cfg->queue.next;
	while (node)
	{
		md5.object = node->content;
		if (md5.object->type == file && ((md5.fd = md5.object->fd) || 1))
			md5_readin(&md5);
		else if (md5.object->type == string)
			md5_string(&md5);
		node = node->next;
	}//*/
	return (md5.ret);
}
