/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequeue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 01:34:41 by viwade            #+#    #+#             */
/*   Updated: 2019/10/17 14:55:04 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_dequeue(t_queue *queue)
{
	void	*content;
	t_node	*node;

	if (!queue || !queue->next)
		return (0);
	node = queue->next;
	while (node && node->next)
		node = node->next;
	queue->last = node;
	content = node->content;
	ft_memdel((void **)&node);
	return (content);
}
