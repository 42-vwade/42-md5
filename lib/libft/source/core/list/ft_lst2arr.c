/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 03:58:52 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	**ft_lst2arr(t_list *lst)
{
	size_t	i;
	size_t	n;
	void	**arr;

	if (!lst)
		return (NULL);
	i = 0;
	n = ft_lstlen(lst);
	if ((arr = (void **)malloc(sizeof(*arr) * n)))
		while (lst)
		{
			arr[i++] = lst->content;
			lst = lst->next;
		}
	return (arr);
}
