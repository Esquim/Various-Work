/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/05/03 14:49:21 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo/best_fit.h"

void		best_fit_init(t_ctx *ctx)
{
	ctx->fn.malloc = best_fit_malloc;
	ctx->fn.realloc = best_fit_realloc;
	ctx->fn.free = best_fit_free;
	ctx->fn.show_alloc_mem = best_fit_show_alloc_mem;
}
