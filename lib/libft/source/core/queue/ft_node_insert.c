/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:54:29 by viwade            #+#    #+#             */
/*   Updated: 2019/10/17 01:08:27 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Inserts a new node after the top of stack.
**	Unlike push, it will not change the top node. Only the nodes after it.
**	If there is no top node, it will set it to the new node. Defaults to push.
*/

void
	ft_node_insert(t_node *node, t_queue *queue)
{
	if (!node || (!queue || !queue->next || !queue->last))
		return ;
	queue->last->next = node->next;
	node->next = queue->next;
}
