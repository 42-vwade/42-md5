/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstr_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:12:24 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	*tstr_new(char *s)
{
	t_str	*new;

	if (!(new = (t_str *)malloc(sizeof(t_str))))
		return (NULL);
	new->str = s;
	new->length = s ? ft_strlen(s) : 0;
	return (new);
}

t_str	*tstr_dup(char *s)
{
	t_str	*new;

	new = tstr_new(ft_strdup(s));
	return (new);
}

t_str	*tstr_dup_free(char *s)
{
	t_str	*new;

	new = tstr_new(ft_strdup(s));
	ft_free(s);
	return (new);
}

void	tstr_free(t_str *s)
{
	ft_free(s->str);
	ft_free(s);
}
