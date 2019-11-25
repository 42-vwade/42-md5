/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 02:21:55 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:49:21 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	asterisk_locate(va_list v_ap, const char *f)
{
	size_t	i;
	size_t	args;
	int		value;
	va_list	ap;

	i = 0;
	va_copy(ap, v_ap);
	MATCH((*(f++) != '*'), RET(0));
	MATCH(!ft_isdigit(*f), RET(va_arg(ap, int)));
	(args = ft_atoi(f))
		|| (args = 1);
	while (args--)
		value = va_arg(ap, int);
	va_end(ap);
	return (value);
}
