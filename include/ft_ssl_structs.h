/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:50:20 by viwade            #+#    #+#             */
/*   Updated: 2019/12/19 14:45:13 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_STRUCTS_H
# define FT_SSL_STRUCTS_H
# include "ft_ssl.h"

enum	e_error {
	no_param = 1,
	read_error,
	mode_undefined
};

enum	e_types {
	string,
	file
};

enum	e_modes {
	UNDEFINED,
	MD5,
	SHA256,
	MODE_SELECT
};

typedef struct s_option	t_option;
typedef struct s_config	t_config;
typedef struct s_object	t_object;
typedef struct s_mode_table	t_mode_table;
typedef struct s_jump_table	t_jump_table;

/*
**	OPTION
**	-s	<string>
**		Print a checksum of the given string.
**	-p	STDIN: <string> ^D
**		Echo stdin to stdout and append the checksum to stdout.
**	-q	<string>
**		Quiet mode - only the checksum is printed out.  Overrides the -r
**			option.
**	-r	<string>
**		Reverses the format of the output.  This helps with visual diffs.
**			Does nothing when combined with the -ptx options.
**	-t	<string>
**		Run a built-in time trial.
**	-x	<string>
**		Run a built-in test script.
**	https://www.freebsd.org/cgi/man.cgi?query=md5&sektion=1
*/

struct	s_object
{
	int				fd;
	char			*data;
	unsigned long	length;
	unsigned long	offset;
	unsigned char	type:	7;
	unsigned char	free:	1;
};

struct	s_option
{
	unsigned char	a:	1;
	unsigned char	b:	1;
	unsigned char	c:	1;
	unsigned char	d:	1;
	unsigned char	e:	1;
	unsigned char	f:	1;
	unsigned char	g:	1;
	unsigned char	h:	1;
	unsigned char	i:	1;
	unsigned char	j:	1;
	unsigned char	k:	1;
	unsigned char	l:	1;
	unsigned char	m:	1;
	unsigned char	n:	1;
	unsigned char	o:	1;
	unsigned char	p;
	unsigned char	q:	1;
	unsigned char	r:	1;
	unsigned char	s:	1;
	unsigned char	t:	1;
	unsigned char	u:	1;
	unsigned char	v:	1;
	unsigned char	w:	1;
	unsigned char	x:	1;
	unsigned char	y:	1;
	unsigned char	z:	1;
};

struct	s_mode_table
{
	char	*func;
	int		(*f)(int, char **);
};

struct	s_jump_table
{
	char	*mode;
	int		(*func)(t_config *);
};

struct	s_config
{
	int			argc;
	char		**argv;
	char		*prgnm;
	char		verb[32];
	int			error;
	int			errno;
	unsigned	c;
	int			(*mode)(t_config *);
};

#endif
