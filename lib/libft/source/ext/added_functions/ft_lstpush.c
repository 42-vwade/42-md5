/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 06:17:09 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Takes the address of a pointer to a list node as argument.
**	Takes a pointer to a valid list node as argument.
**	Function checks if current node exists. If not, the new node is placed.
**	Otherwise,
*/

void
	ft_lstpush(t_list **list, t_list *new)
{
	t_list	*push;

	if (!list[0])
	{
		list[0] = new;
		return ;
	}
	push = list[0];
	while ((push->next))
		push = push->next;
	if (!push->content)
	{
		ft_lstdelone(&push, ft_del);
		push = new;
	}
	else
		push->next = new;
}
