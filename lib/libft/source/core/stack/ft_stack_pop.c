/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:54:29 by viwade            #+#    #+#             */
/*   Updated: 2019/09/28 01:12:54 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_stack_pop(t_stack *stack)
{
	void	*content;
	t_node	*node;

	if (!stack || !stack->top)
		return (0);
	node = stack->top;
	content = node->content;
	stack->top = node->next;
	ft_memdel((void **)&node);
	return (content);
}
