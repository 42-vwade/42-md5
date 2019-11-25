/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_macros.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 00:37:49 by viwade            #+#    #+#             */
/*   Updated: 2019/11/18 16:23:08 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MACROS_H
# define LIBFT_MACROS_H
# include <stdlib.h>
# include "libft.h"

/*
**	--	DATA TYPE DEFINITIONS	--
**	A perfunctory glossary of uniform data types, which will be used to
**	assist in clarifying return values and desired argument types.
*/

# define FT_SIZE	size_t
# define FT_SSIZE	ssize_t
# define FT_NBR		t_num
# define FT_STR		char *
# define FT_WSTR	wchar_t *
# define FT_LSTR	int *
# define FT_TSTR	t_str
# define FT_INT		int
# define FT_UINT	unsigned int
# define FT_LIST	t_list *
# define FT_VOID	void
# define FT_VOIDP	void *
# define FT_D		double
# define FT_LD		long double
# define FT_FLOAT	float
# define FT_LL		long long
# define FT_ULL		unsigned long long
# define t_bool		signed int

/*
**	--	DATA TYPE SHORTHAND	--
*/

# define LL	FT_LL
# define ULL FT_ULL
# define NBR t_num
# define RET		return
# define RETURN		return
# define BREAK		break
# define MATCH(a,b) if ((a)) b
# define OR(a,b)	else if ((a)) b
# define ELSE(a)	else a
# define ANY2(x,a,b)		((x == a)||(x == b))
# define ANY3(x,a,b,c)		((x == a)||(x == b)||(x == c))
# define ANY4(x,a,b,c,d)	((x == a)||(x == b)||(x == c)||(x == d))
# define ANY5(x,a,b,c,d,e)	((x == a)||(x == b)||(x == c)||(x == d)||(x == e))
# define GROUP(x)	{x}
# define LINE(x)	x;
# define IF_C(c,t)		{if((c)){t;}}
# define IF_E(c,a,b)	{if((c)){a;}else{b;}}
# define _B(a, b)          {a;b;}

# define ABS(n) ((n) < 0 ? -(n) : (n))
# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define SQ(a)      ((a) * (a))
# define PYTH(a,b,c)    (SQ(a) + SQ(b) + SQ(c))

/*
**	TYPE DEFINITION
*/

# define _TD_LD		typedef long double	ld_t
# define _TD_D		typedef double	db_t
# define _TD_LL		typedef long long	ll_t
# define _TD_ULL	typedef unsigned long long	ull_t
# define _TD_BSTR	typedef struct s_byte_string bstr_t

_TD_LD;
_TD_D;
_TD_LL;
_TD_ULL;
_TD_BSTR;

#endif
