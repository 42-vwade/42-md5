/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:47:37 by viwade            #+#    #+#             */
/*   Updated: 2019/10/21 22:25:34 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include "ft_ssl_include.h"

int		ft_ssl(t_config *config);
int		ssl_config(int argc, char **argv);
int		md5(t_config *config);
int		sha256(t_config *config);
int		ssl_md5(int n, char **v);
int		ssl_sha256(int n, char **v);

#endif
