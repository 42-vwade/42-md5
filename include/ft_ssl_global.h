/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_global.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:50:20 by viwade            #+#    #+#             */
/*   Updated: 2019/10/21 08:22:07 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_GLOBAL_H
# define FT_SSL_GLOBAL_H
# include "ft_ssl_structs.h"


const t_mode_table	g_mode[] = {
	{"md5", ssl_md5},
	{"sha256", ssl_sha256},
	{0, 0}
};

const t_jump_table	g_jumptable[] = {
	{"md5", md5},
	{"sha256", sha256},
	{0, 0}
};

#endif
