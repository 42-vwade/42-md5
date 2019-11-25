/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 04:28:50 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;

	if ((new = (t_list *)malloc(sizeof(*new))))
		if ((new->content = ft_memalloc(content_size)))
		{
			if (!content)
				new->content = NULL;
			else
				new->content = ft_memcpy(new->content, content, content_size);
			new->content_size = (content) ? content_size : 0;
			new->next = NULL;
		}
	return (new);
}
