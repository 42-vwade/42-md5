/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:54:29 by viwade            #+#    #+#             */
/*   Updated: 2019/10/16 23:19:52 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_stack_push(t_stack *stack, void *content)
{
	t_node	*new;

	if (!stack)
		return ;
	if (!(new = malloc(sizeof(t_node))))
		ft_error("ft_stack_push: <node> malloc error");
	new->next = stack->top;
	new->content = content;
	stack->top = new;
}
