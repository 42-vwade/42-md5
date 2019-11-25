/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:44:27 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_astrcmp(char **s1, char **s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i])
		if (!s1[i] && !s2[i])
			return (1);
		else if (!s1[i] || !s2[i])
			return (0);
		else if (!ft_strcmp(s1[i], s2[i]))
			return (0);
		else
			i++;
	return (1);
}
