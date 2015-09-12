/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/05/04 17:49:12 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_malloc.h"
#include "algo/best_fit.h"

static t_mblk	*best_fit_glue_block(t_mblk *block)
{
	if (block->next && !block->next->allocated)
	{
		block->size += BLOCK_SIZE(block->next->size);
		block->next = block->next->next;
		if (block->next)
			block->next->prev = block;
	}
	return (block);
}

void			best_fit_free(t_ctx *ctx, void *p)
{
	t_mblk	*block;

	if (!best_fit_valid_pointer(ctx, p))
		return ;
	block = BLOCK_PTR(p);
	block->allocated = false;
	if (block->prev && !block->prev->allocated)
		block = best_fit_glue_block(block->prev);
	if (block->next)
		block = best_fit_glue_block(block);
	if (!block->next)
	{
		if (block->prev)
			block->prev->next = NULL;
		else
			ctx->root = NULL;
		brk(block);
	}
}
