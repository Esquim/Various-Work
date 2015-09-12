/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_fit.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/05/03 14:47:10 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_BEST_FIT_H
# define ALGO_BEST_FIT_H

# include <stddef.h>
# include <stdbool.h>
# include "ft_malloc.h"
# include "common_fit.h"

void		*best_fit_malloc(t_ctx *ctx, size_t size);
void		*best_fit_realloc(t_ctx *ctx, void *p, size_t size);
void		best_fit_free(t_ctx *ctx, void *p);

bool		best_fit_valid_pointer(t_ctx *ctx, void *p);
t_mblk		*best_fit_find_block(t_ctx *ctx, t_mblk **last, size_t size);
void		best_fit_split_block(t_mblk *block, size_t size);
t_mblk		*best_fit_extend_heap(t_mblk *prev, size_t size);

void		best_fit_show_alloc_mem(t_ctx *ctx);

void		best_fit_init(t_ctx *ctx);

#endif
