/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:14:53 by viwade            #+#    #+#             */
/*   Updated: 2019/10/17 10:18:37 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H
# include "ft_ssl.h"
# define A	0x67452301
# define B	0xefcdab89
# define C	0x98BADCFE
# define D	0x10325476
// # define F(b,c,d)	((b & c) | (~b & d))
// # define G(b,c,d)	((d & b) | (~d & c))
// //# define G(b,c,d)	(((b) & (c)) | ((b) & ~(d)))
// # define H(b,c,d)	((b ^ c ^ d))
// # define I(b,c,d)	((c ^ (b |~ d)))
// # define R(x,n)		(((x) << (n)) | ((x) >> (32 - (n))))
// # define S(a,b,c,d)	{a = d; d = c; c = b;}
# define HEXA		"0123456789abcdef"

enum e_mode{
	md5_str = 1,
	md5_fd = 2
};

typedef union u_digest	t_digest;
typedef struct s_md5	t_md5;

union	u_128bit
{
	char	b[16];
	int		w[4];
	long	l[2];
};


union	u_digest
{
	char			b[64];
	int				w[16];
	union u_128bit	d[4];
};

struct	s_md5
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	f;
	unsigned int	g;
	unsigned int	fd;
	signed long		nb;
	unsigned long	i;
	unsigned long	len;
	unsigned long	length;
	unsigned char	block[64];
	unsigned int	message[16];
	unsigned int	result[4];
	signed int		ret;
	t_digest		digest;
	t_object		object;
	t_option		option;
};

void		md5_algorithm(t_md5 *md5_object);
void		md5_input(int fd, char *string, t_md5 *md5);
t_bool		md5_args(int n, char **v, t_md5 *md5);
unsigned	ff(unsigned i, unsigned *f, int a[3], int mode);
unsigned	m_rr(unsigned value, unsigned shift);
void		m_rotate(unsigned *a, unsigned *b, unsigned *c, unsigned *d);

#endif
