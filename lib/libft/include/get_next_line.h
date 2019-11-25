/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 21:04:41 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FD_LIMIT 8192
# define BUFF_SIZE 1048576

# include "libft.h"
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>

struct	s_file
{
	size_t	ndx;
	size_t	len;
	char	*str;
};
typedef struct s_file	t_file;

int		get_next_line(const int fd, char **line);

#endif
