/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/05/03 14:50:15 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo/first_fit.h"

void		first_fit_init(t_ctx *ctx)
{
	ctx->fn.malloc = first_fit_malloc;
	ctx->fn.realloc = first_fit_realloc;
	ctx->fn.free = first_fit_free;
	ctx->fn.show_alloc_mem = first_fit_show_alloc_mem;
}
