/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enqueue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 01:15:48 by viwade            #+#    #+#             */
/*   Updated: 2019/10/17 01:13:07 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_enqueue(t_queue *queue, void *content)
{
	t_node	*node;

	if (!queue)
		return ;
	if (!(node = malloc(sizeof(t_node))))
		ft_error("ft_enqueue: <node> failed to allocate memory");
	node->content = content;
	node->next = NULL;
	queue->last = node;
	node = queue->next;
	while (node && node->next)
		node = node->next;
	node->next = queue->last;
}
