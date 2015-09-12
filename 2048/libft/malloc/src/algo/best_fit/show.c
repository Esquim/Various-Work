/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/05/03 14:49:50 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_malloc.h"
#include "algo/best_fit.h"
#include <libft.h>

void		best_fit_show_alloc_mem(t_ctx *ctx)
{
	t_mblk	*block;

	ft_printf("break : %p\n", sbrk(0));
	block = ctx->root;
	while (block)
	{
		if (block->allocated)
		{
			ft_printf("%p - %p : %zd octets\n",
				DATA_PTR(block),
				DATA_PTR(block) + block->size,
				block->size);
		}
		block = block->next;
	}
}
