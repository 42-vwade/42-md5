/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:01:40 by viwade            #+#    #+#             */
/*   Updated: 2019/09/19 19:00:11 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCTS_H
# define FT_PRINTF_STRUCTS_H
# include <stdarg.h>
# include <stdint.h>
# include <sys/types.h>
# define U_DOUBLE typedef union u_double	u_double
# define SPECIFIER_LIST	"%cspdiouxfeganb"

/*
**	ENUMERATION
*/

enum	e_flags {
	plus = 1 << 0,
	minus = 1 << 1,
	zero = 1 << 2,
	hash = 1 << 3,
	space = 1 << 4,
	neg = 1 << 7
};

enum	e_length {
	hh = sizeof(char),
	h = sizeof(short),
	l = sizeof(long),
	ll = sizeof(long long),
	j = sizeof(intmax_t),
	z = sizeof(size_t),
	t = sizeof(size_t),
	LD = sizeof(long double)
};

/*
**	UNION STRUCT
*/

U_DOUBLE;

union	u_double
{
	ULL		ld;
	double	d;
};

/*
**	TYPE DEFINITIONS
*/

typedef struct s_format	t_format;
typedef struct s_param	t_param;
typedef struct s_type	t_type;

/*
**	FUNCTION DEFINITION
*/

typedef int	(*t_func) (t_format *);

/*
**	STRUCTS
*/
struct	s_param
{
	ull_t	tick;
	ull_t	flags;
	ull_t	width;
	ull_t	precision;
	ull_t	length;
};

struct	s_format
{
	va_list		ap;
	const char	*format;
	t_func		jump[256];
	t_func		f;
	t_param		p;
	char		color;
	char		*sign;
	char		*z_pad;
	char		*pad;
	char		*prefix;
	t_list		*list;
	char		*str;
	size_t		len;
	int			error;
	void		*v;
	void		*output;
	void		*encode;
	void		*tmp;
	size_t		write;
};

struct	s_type
{
	char	type;
	t_func	f;
};

#endif
