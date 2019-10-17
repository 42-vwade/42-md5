/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:50:20 by viwade            #+#    #+#             */
/*   Updated: 2019/10/17 11:56:26 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_STRUCTS_H
# define FT_SSL_STRUCTS_H
# include "ft_ssl.h"

typedef struct s_option	t_option;

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

struct s_option
{
	unsigned char	s:	1;
	unsigned char	p:	1;
	unsigned char	q:	1;
	unsigned char	r:	1;
	unsigned char	t:	1;
	unsigned char	x:	1;
	t_node			*strings;
};

#endif
