/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/05/03 14:50:43 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "algo/first_fit.h"
#include "algo/best_fit.h"

void		ft_algo_init(t_ctx *ctx)
{
	if (ctx->cfg.algo_type == FIRST_FIT)
		first_fit_init(ctx);
	else if (ctx->cfg.algo_type == BEST_FIT)
		best_fit_init(ctx);
	else
	{
		ft_mlog(ctx, INFO, "No algo choice, using default(first_fit).");
		first_fit_init(ctx);
	}
}
