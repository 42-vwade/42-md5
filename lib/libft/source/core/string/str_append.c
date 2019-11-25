/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_append.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:55:41 by viwade            #+#    #+#             */
/*   Updated: 2019/09/26 14:43:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define FREE_NONE	0
#define FREE_LEFT	1
#define FREE_RIGHT	2
#define FREE_ALL	3
#define DEL(f,x)			f((void**)x)
#define APPEND_0(s,a,b,f,f2) {(s) = f(a,b);}
#define APPEND_1(s,a,b,f,f2) {(s) = f(a,b);DEL(f2,&a);}
#define APPEND_2(s,a,b,f,f2) {(s) = f(a,b);DEL(f2,&b);}
#define APPEND_3(s,a,b,f,f2) {(s) = f(a,b);DEL(f2,&a);DEL(f2,&b);}
#define MODE_0(s,x,a,b,f,f2) if(x==FREE_NONE)	APPEND_0(s,a,b,f,f2)
#define MODE_1(s,x,a,b,f,f2) if(x==FREE_LEFT)	APPEND_1(s,a,b,f,f2)
#define MODE_2(s,x,a,b,f,f2) if(x==FREE_RIGHT)	APPEND_2(s,a,b,f,f2)
#define MODE_3(s,x,a,b,f,f2) if(x==FREE_ALL)	APPEND_3(s,a,b,f,f2)

char	*ft_append(const char *s1, const char *s2, int mode)
{
	void	*string;

	if ((unsigned)mode > FREE_ALL)
		ft_error("ft_append: no mode specified");
	string = 0;
	MATCH(!s1 && (mode == 1 || mode == 3), mode -= 1);
	MATCH(!s2 && (mode == 2 || mode == 3), mode = mode == 3 ? 1 : 0);
	MODE_0(string, mode, s1, s2, ft_strjoin, ft_memdel);
	MODE_1(string, mode, s1, s2, ft_strjoin, ft_memdel);
	MODE_2(string, mode, s1, s2, ft_strjoin, ft_memdel);
	MODE_3(string, mode, s1, s2, ft_strjoin, ft_memdel);
	return (string);
}
