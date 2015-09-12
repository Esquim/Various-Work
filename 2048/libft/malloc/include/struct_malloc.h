/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_malloc.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/05/04 18:20:49 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_MALLOC_H
# define STRUCT_MALLOC_H

# include <stddef.h>

typedef enum			e_log_level
{
	ALL = 0,
	DEBUG = 1,
	INFO = 2,
	WARNING = 3,
	ERROR = 4,
	NOTHING = 5,
}						t_log_level;

typedef enum			e_algo_type
{
	FIRST_FIT,
	BEST_FIT
}						t_algo_type;

typedef struct s_cfg	t_cfg;
typedef struct s_stat	t_stat;
typedef struct s_fn		t_fn;
typedef struct s_ctx	t_ctx;

typedef void			*(*t_malloc_fn)(t_ctx *, size_t);
typedef void			*(*t_realloc_fn)(t_ctx *, void *, size_t);
typedef void			(*t_free_fn)(t_ctx *, void *);
typedef void			(*t_show_alloc_mem_fn)(t_ctx *);

struct					s_cfg
{
	t_log_level		log_level;
	t_algo_type		algo_type;
	bool			abort_error;
	bool			init_block;
	bool			abort_on_low_memory;
	bool			print_allocated;
	bool			print_unallocated;
	bool			print_nb_blocks;
	bool			print_max_nb_blocks;
};

struct					s_fn
{
	t_malloc_fn			malloc;
	t_realloc_fn		realloc;
	t_free_fn			free;
	t_show_alloc_mem_fn	show_alloc_mem;
};

struct					s_stat
{
	size_t		nb_blocks;
	size_t		nb_blocks_max;
};

struct					s_ctx
{
	void			*root;
	t_cfg			cfg;
	t_fn			fn;
	t_stat			stat;
};

#endif
