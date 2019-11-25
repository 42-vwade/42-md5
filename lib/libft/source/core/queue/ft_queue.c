/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 06:42:14 by viwade            #+#    #+#             */
/*   Updated: 2019/10/16 23:34:51 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue
	*ft_queue(void)
{
	t_queue	*new;

	if (!(new = malloc(sizeof(t_queue))))
		ft_error("ft_queue: <queue> failed to initialize");
	*(unsigned char *)&new->free = ~0;
	new->next = 0;
	new->last = 0;
	return (new);
}
