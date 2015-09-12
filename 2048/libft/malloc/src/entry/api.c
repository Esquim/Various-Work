/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/05/04 17:54:21 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include "ft_malloc.h"
#include "entry_malloc.h"

void		*ft_malloc(size_t size)
{
	void		*p;

	context_acquire();
	if (g_ctx.cfg.print_allocated)
		ft_mlog(&g_ctx, INFO, "malloc(%zd)", size);
	p = g_ctx.fn.malloc(&g_ctx, size);
	if (!p)
		ft_mlog(&g_ctx, ERROR, "null pointer exception!");
	else if (g_ctx.cfg.init_block)
		memset(p, 0, size);
	if (g_ctx.cfg.print_nb_blocks)
		ft_mlog(&g_ctx, INFO, "Blocks: %zd", g_ctx.stat.nb_blocks);
	context_release();
	return (p);
}

void		*ft_calloc(size_t n, size_t size)
{
	void		*p;

	context_acquire();
	if (g_ctx.cfg.print_allocated)
		ft_mlog(&g_ctx, INFO, "calloc(%zd, %zd)", n, size);
	context_release();
	p = ft_malloc(n * size);
	context_acquire();
	if (p)
		memset(p, 0, n * size);
	else
		ft_mlog(&g_ctx, ERROR, "null pointer exception!");
	if (g_ctx.cfg.print_nb_blocks)
		ft_mlog(&g_ctx, INFO, "Blocks: %zd", g_ctx.stat.nb_blocks);
	context_release();
	return (p);
}

void		*ft_realloc(void *p, size_t size)
{
	void		*pp;

	context_acquire();
	if (g_ctx.cfg.print_allocated)
		ft_mlog(&g_ctx, INFO, "realloc(%p, %zd)", p, size);
	if (size == 0)
		return (NULL);
	pp = g_ctx.fn.realloc(&g_ctx, p, size);
	if (!pp)
		ft_mlog(&g_ctx, ERROR, "null pointer exception!");
	else if (g_ctx.cfg.init_block)
		memset(pp, 0, size);
	if (g_ctx.cfg.print_nb_blocks)
		ft_mlog(&g_ctx, INFO, "Blocks: %zd", g_ctx.stat.nb_blocks);
	context_release();
	return (pp);
}

void		ft_free(void *p)
{
	context_acquire();
	if (!p)
		ft_mlog(&g_ctx, WARNING, "freeing null pointer.");
	if (g_ctx.cfg.print_unallocated)
		ft_mlog(&g_ctx, INFO, "free(%p)", p);
	g_ctx.fn.free(&g_ctx, p);
	if (g_ctx.cfg.print_nb_blocks)
		ft_mlog(&g_ctx, INFO, "Blocks: %zd", g_ctx.stat.nb_blocks);
	context_release();
}

void		ft_show_alloc_mem(void)
{
	context_acquire();
	g_ctx.fn.show_alloc_mem(&g_ctx);
	context_release();
}
