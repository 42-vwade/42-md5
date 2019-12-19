/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:14:33 by viwade            #+#    #+#             */
/*   Updated: 2019/12/19 15:28:28 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

const unsigned
	g_md5_shift[16] = {
	7, 12, 17, 22,
	5, 9, 14, 20,
	4, 11, 16, 23,
	6, 10, 15, 21
};

const unsigned
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

void
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

int
	md5(t_config *cfg)
{
	t_md5	md5;
	size_t	n = 2;

	ft_bzero(&md5, sizeof(md5));
	ft_memcpy(md5.result, (int[]){A, B, C, D}, sizeof(int[4]));
	if (!md5_args(cfg->argc - 2, &cfg->argv[2], &md5) && 0)
		md5_input(0, 0, &md5);
	else
	{
		if (md5.option.p)
			md5_input(md5.option.p = 0, 0, &md5);
		while (n < cfg->argc && !(md5.object.data = 0))
			if (!('-' == *cfg->argv[n]) ||
					((md5.object.data = ft_strchr(cfg->argv[n], 's')) && 0))
				break ;
			else if (md5.object.data && md5.object.data[1] && ((n += 1) || 1))
				md5_input(-1, &md5.object.data[1], &md5);
			else if ((md5.object.data && n + 1 < cfg->argc) && ((n += 1) || 1))
				md5_input(-1, cfg->argv[n++], &md5);
			else
				break ; //md5_input(0, cfg->argv[n++], &md5);
		while (n < cfg->argc)
			md5_input(0, cfg->argv[n++], &md5);
	}
	return (md5.ret);
}
