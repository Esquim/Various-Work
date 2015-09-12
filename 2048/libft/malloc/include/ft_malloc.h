/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/04/28 15:50:14 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stddef.h>
# include <stdbool.h>
# include "struct_malloc.h"
# include "macros_malloc.h"

/*
** conf/
*/
void		ft_conf_init(t_ctx *ctx);

/*
** algo/
*/
void		ft_algo_init(t_ctx *ctx);

/*
** log.c
*/
void		ft_mlog(t_ctx *ctx, t_log_level level,
			const char *msg, ...);

#endif
