/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 04:58:47 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	Traverses to end of list.
**	Uses delete function on content of list node.
**	Then deletes the node.
**	Traverse to previous node, repeat.
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst[0]->next)
		ft_lstdel(&(alst[0]->next), del);
	ft_lstdelone(alst, del);
}
