/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 06:24:16 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void
	del(void *ap, size_t len)
{
	ft_bzero(ap, len);
	ft_memdel(&ap);
}

void
	ft_lstpop(t_list **list)
{
	while (list[0]->next)
		list[0] = list[0]->next;
	ft_lstdel(&list[0], del);
}
