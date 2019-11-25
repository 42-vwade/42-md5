/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 06:42:14 by viwade            #+#    #+#             */
/*   Updated: 2019/10/17 01:16:45 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Deletes queue and frees memory, if needed.
**	Time complexity O(n) == 5(n - 1) + 12 (steps)
*/

void
	ft_queue_del(t_queue *queue)
{
	t_node	*node;

	if ((!queue || !queue->next) || (queue->last = 0))
		return ;
	node = queue->next;
	while (node)
	{
		node = node->next;
		ft_memdel((void **)&queue->next);
		queue->next = node;
	}
	if (queue->free)
		ft_memdel((void **)&queue);
}
