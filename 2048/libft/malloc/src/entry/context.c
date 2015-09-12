/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/05/04 18:24:42 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "ft_malloc.h"
#include "entry_malloc.h"

static pthread_mutex_t	g_context_lock = PTHREAD_MUTEX_INITIALIZER;

t_ctx			g_ctx =
{
	.root						= NULL,
	.cfg =
	{
		.log_level				= NOTHING,
		.abort_error			= false,
		.init_block				= false,
		.abort_on_low_memory	= false,
		.print_allocated		= false,
		.print_unallocated		= false,
		.print_nb_blocks		= false,
		.print_max_nb_blocks	= false,
		.algo_type				= FIRST_FIT,
	},
	.fn =
	{
		.malloc					= NULL,
		.realloc				= NULL,
		.free					= NULL,
	},
	.stat =
	{
		.nb_blocks				= 0,
		.nb_blocks_max			= 0,
	},
};

void			context_acquire(void)
{
	pthread_mutex_lock(&g_context_lock);
}

void			context_release(void)
{
	pthread_mutex_unlock(&g_context_lock);
}
