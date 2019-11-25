/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 01:15:48 by viwade            #+#    #+#             */
/*   Updated: 2019/10/16 23:47:33 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_queue_last(t_queue *queue, void *content)
{
	t_node	*node;

	if (!queue)
		return ;
	if (!(node = malloc(sizeof(t_node))))
		ft_error("ft_enqueue: <node> failed to allocate memory");
	node->content = content;
	node->next = NULL;
	if (queue->last)
		queue->last->next = node;
	queue->last = node;
}
