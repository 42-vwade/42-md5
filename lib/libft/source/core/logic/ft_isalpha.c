/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 02:20:13 by viwade            #+#    #+#             */
/*   Updated: 2018/11/09 17:22:03 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int
	isvalid(int c)
{
	if ((unsigned)c < 0x100 || c == -1)
		return (1);
	return (0);
}

int
	ft_isalpha(int c)
{
	unsigned char a;

	a = (unsigned char)c;
	if (isvalid(c))
		if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
			return (1);
	return (0);
}
