/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 21:04:41 by viwade            #+#    #+#             */
/*   Updated: 2019/01/17 02:15:13 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int
	readline(t_file *file, int fd, char **line)
{
	int			ret;
	long int	nb;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	file->str = (file->str) ? file->str : ft_strnew(0);
	while ((nb = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[nb] = 0;
		tmp = file->str;
		file->str = ft_strjoin(tmp, buf);
		free(tmp);
	}
	if ((tmp = ft_strchr(&file->str[file->ndx], '\n')))
		file->len = (size_t)(tmp - &file->str[file->ndx]);
	else
		file->len = ft_strlen(&file->str[file->ndx]);
	if ((ret = !!(file->str[file->ndx])))
		line[0] = ft_strsub(file->str, (unsigned int)file->ndx, file->len);
	file->ndx += (tmp) ? file->len + 1 : file->len;
	return (ret);
}

int
	get_next_line(const int fd, char **line)
{
	static t_file	file[FD_LIMIT];

	if (fd < 0 || fd > FD_LIMIT - 1 || !line || read(fd, 0, 0) == -1)
		return (-1);
	return (readline(&file[fd], fd, line));
}

/*
**	COMMENTS MAY GO HERE
**	FUNCTION: GET_NEXT_LINE
**	First phase.
**	Set up static array to hold all possible file descriptors.
**	Defined with macro. FD_LIMIT
**	I have elected to use a struct to hold a string, index, and length of line.
**	Error check. Ensure fd is valid, that 'line' is valid, and fd can be read.
**	All checks pass. Return value of 'readline.'
**
**	Second phase.
**	Initialize string, if invalid.
**	Read contents of file by joining data buffer to the end of my file string.
**	Loop and free excess data each cycle.
**	Search for next newline char. Assign a marker.
**	Obtain length of line using 'newline' marker and current file index.
**	Else get length of remainder of data in file. (Null-terminate)
**	File index updates last. If char at index is null, return 0. Else return 1.
*/
