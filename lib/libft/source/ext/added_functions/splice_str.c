/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splice_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 05:41:00 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Function takes a string, splits it, and inserts a second at the specified
**	index.
**	Creates a total of three parts.
**	Returns the recombined string.
*/

char
	*splice_str(char *source, char *fragment, size_t ndx)
{
	if (!source)
		return (NULL);
	if (!ndx || !fragment)
		return (source);
	return (
		ft_strjoin_free(
			ft_strsub(source, 0, ndx),
			ft_strjoin_free(
				ft_strdup(fragment),
				ft_strsub(ft_strdup(source), ndx, ft_strlen(&source[ndx])))));
}

char
	*search_and_splice(char *source, char *needle, char *fragment)
{
	char	*gem;
	size_t	len;

	if (!source)
		return (NULL);
	if (!needle || !fragment || (len = ft_strlen(fragment)) > ft_strlen(source))
		return (source);
	if ((gem = ft_strstr(source, needle)))
		return (splice_str(source, fragment, &gem[len] - source));
	else
		return (splice_str(source, fragment, 0));
	return (source);
}
