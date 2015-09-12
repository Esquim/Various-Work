/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/05/04 18:47:25 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include "ft_malloc.h"
#include "algo/best_fit.h"

static bool	check_extend_block(t_ctx *ctx, t_mblk *block, size_t size)
{
	(void)ctx;
	if (block->next && !block->next->allocated)
		return (block->size + BLOCK_SIZE(block->next->size) >= size);
	return (false);
}

static void	*extend_block(t_ctx *ctx, t_mblk *block, size_t size)
{
	(void)ctx;
	block->size += BLOCK_SIZE(block->next->size);
	if (block->next->next)
		block->next->next->prev = block;
	block->next = block->next->next;
	if ((block->size - size) >= sizeof(t_mblk))
		best_fit_split_block(block, size);
	return (DATA_PTR(block));
}

void		*best_fit_realloc(t_ctx *ctx, void *p, size_t size)
{
	t_mblk		*block;
	void		*np;

	(void)ctx;
	if (!p)
		return (ctx->fn.malloc(ctx, size));
	if (!best_fit_valid_pointer(ctx, p))
		return (NULL);
	size = ALIGN4(size);
	block = BLOCK_PTR(p);
	if (check_extend_block(ctx, block, size))
		return (extend_block(ctx, block, size));
	np = ctx->fn.malloc(ctx, size);
	memcpy(np, p, MIN(block->size, size));
	ctx->fn.free(ctx, p);
	return (np);
}
