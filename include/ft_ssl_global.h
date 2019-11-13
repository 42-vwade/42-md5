/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_global.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:50:20 by viwade            #+#    #+#             */
/*   Updated: 2019/11/12 17:10:00 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_GLOBAL_H
# define FT_SSL_GLOBAL_H
# include "ft_ssl.h"
# include "ft_ssl_structs.h"

const t_jump_table	g_jumptable[] = {
	{"undefined", 0},
	{"md5", md5},
	{"sha256", sha256},
	{0, 0}
};

#endif
