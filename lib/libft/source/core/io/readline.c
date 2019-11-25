/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 08:22:50 by viwade            #+#    #+#             */
/*   Updated: 2019/09/29 09:11:32 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#define BUFSIZ	1024

/*
** Read from file descriptor <fd> until EOF.
** Sets <line> to the line read from <fd> .
** Returns 1 if a line was read, else 0.
*/

int
	readline(int fd, char **line)
{
	static char	*input;
	char		*tmp;
	char		buf[BUFSIZ + 1];
	int			bytes_read;

	while ((bytes_read = read(fd, buf, BUFSIZ)) > 0)
	{
		buf[bytes_read] = 0;
		((tmp = input) && (input = ft_strjoin(input, buf))) ||
			(input = ft_strdup(buf));
		if (tmp)
			free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	tmp = ft_strchr(input, '\n');
	line[0] = tmp ? ft_strsub(input, 0, tmp - input) : ft_strdup(input);
	(*tmp == '\n') && (tmp = input) &&
		(input = ft_strdup(ft_strchr(input, '\n') + 1));
	if (tmp)
		free(tmp);
	return (bytes_read || (input && **line));
}
