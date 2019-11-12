/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c.m                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 08:30:11 by viwade            #+#    #+#             */
/*   Updated: 2019/11/12 13:33:17 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int	ft_ssl(t_config *c)
{
	t_node	*node;

	node = c->queue.next;
	while (node)
	{
		c->mode(node->content);
		node = node->next;
	}
}
