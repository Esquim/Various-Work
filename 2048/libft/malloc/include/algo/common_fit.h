/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_fit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/05/04 18:29:35 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_FIT_H
# define COMMON_FIT_H

# include <stddef.h>
# include <stdbool.h>

# define DATA_SIZE(size) ((size) - sizeof(t_mblk))
# define BLOCK_SIZE(size) ((size) + sizeof(t_mblk))

# define DATA_PTR(block) ((void *)((char *)(block) + sizeof(t_mblk)))
# define BLOCK_PTR(p) ((t_mblk *)((char *)(p) - sizeof(t_mblk)))

typedef struct		s_mblk
{
	short			magic;
	struct s_mblk	*prev;
	struct s_mblk	*next;
	size_t			size;
	bool			allocated;
}					t_mblk;

#endif
