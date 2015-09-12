/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_malloc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/04/28 15:51:29 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTRY_MALLOC_H
# define ENTRY_MALLOC_H

# include "ft_malloc.h"

extern t_ctx	g_ctx;

void		context_acquire();
void		context_release();

#endif
