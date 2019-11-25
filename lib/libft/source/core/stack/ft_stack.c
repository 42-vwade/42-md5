/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 12:01:40 by viwade            #+#    #+#             */
/*   Updated: 2019/09/29 06:46:12 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack
	*ft_stack(void)
{
	t_stack	*new;

	if (!(new = malloc(sizeof(t_stack))))
		ft_error("ft_stack: <stack> failed to initialize");
	*(unsigned char *)&new->free = ~0;
	new->top = NULL;
	return (new);
}
