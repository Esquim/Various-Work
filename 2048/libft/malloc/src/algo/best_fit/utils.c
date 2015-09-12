/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/05/03 14:49:58 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "ft_malloc.h"
#include "algo/best_fit.h"

bool		best_fit_valid_pointer(t_ctx *ctx, void *p)
{
	t_mblk	*block;

	if (!ctx->root)
	{
		errno = ENOMEM;
		return (false);
	}
	if (!(p > (void *)ctx->root && p < sbrk(0)))
	{
		errno = ENOMEM;
		return (false);
	}
	block = BLOCK_PTR(p);
	if (block->magic != FT_MALLOC_MAGIC)
		return (false);
	return (true);
}

t_mblk		*best_fit_find_block(t_ctx *ctx, t_mblk **last, size_t size)
{
	t_mblk	*block;
	t_mblk	*best;

	best = NULL;
	block = ctx->root;
	while (block)
	{
		if (!block->allocated && block->size >= size)
		{
			if (best == NULL || block->size < best->size)
				best = block;
		}
		*last = block;
		block = block->next;
	}
	return (best);
}

void		best_fit_split_block(t_mblk *block, size_t size)
{
	t_mblk	*new_block;

	new_block = (t_mblk *)((char *)block + BLOCK_SIZE(size));
	new_block->magic = FT_MALLOC_MAGIC;
	new_block->prev = block;
	new_block->next = block->next;
	new_block->size = block->size - BLOCK_SIZE(size);
	new_block->allocated = false;
	block->size = size;
	block->next = new_block;
	if (new_block->next)
		new_block->next->prev = new_block;
}

t_mblk		*best_fit_extend_heap(t_mblk *prev, size_t size)
{
	t_mblk	*block;

	block = (t_mblk *)sbrk(BLOCK_SIZE(size));
	if (block == (void *)-1)
		return (NULL);
	block->magic = FT_MALLOC_MAGIC;
	block->prev = prev;
	block->next = NULL;
	block->size = size;
	block->allocated = true;
	if (prev)
		prev->next = block;
	return (block);
}
