/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/05/04 17:49:26 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "ft_malloc.h"
#include "algo/best_fit.h"

static t_mblk	*best_fit_add_elem(t_ctx *ctx, size_t size)
{
	t_mblk	*block;
	t_mblk	*last;

	last = ctx->root;
	block = best_fit_find_block(ctx, &last, size);
	if (block)
	{
		if ((block->size - size) >= sizeof(t_mblk))
			best_fit_split_block(block, size);
		block->allocated = true;
	}
	else
	{
		block = best_fit_extend_heap(last, size);
		if (!block)
			return (NULL);
	}
	return (block);
}

static t_mblk	*best_fit_add_head(t_ctx *ctx, size_t size)
{
	t_mblk	*block;

	block = best_fit_extend_heap(NULL, size);
	if (!block)
		return (NULL);
	ctx->root = block;
	return (block);
}

void			*best_fit_malloc(t_ctx *ctx, size_t size)
{
	t_mblk	*block;

	size = ALIGN4(size);
	if (ctx->root)
		block = best_fit_add_elem(ctx, size);
	else
		block = best_fit_add_head(ctx, size);
	return (DATA_PTR(block));
}
