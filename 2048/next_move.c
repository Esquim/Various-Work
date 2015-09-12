/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:52:20 by apilate           #+#    #+#             */
/*   Updated: 2015/03/01 21:10:46 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "g2048.h"

static void	reset_merge(t_cell board[X][X])
{
	t_cell	*cell;
	int		i;

	i = 0;
	while ((cell = get_cell(board, i, UP)) != NULLPTR)
	{
		cell->merged = 0;
		i++;
	}
}

static void	move_cell(t_cell *cell, int ret, t_cell board[X][X],
						uint8_t *moved)
{
	t_cell	*farthest;
	t_cell	*next;

	farthest = farthest_cell(board, cell->x, cell->y, ret);
	next = next_cell(board, farthest->x, farthest->y, ret);
	if (next != NULLPTR && next->value == cell->value && !(next->merged))
	{
		next->value *= 2;
		cell->value = 0;
	}
	else
	{
		if (farthest != cell)
		{
			farthest->value = cell->value;
			cell->value = 0;
		}
	}
	if (cell->value == 0)
		*moved = 1;
}

void		next_move(int ret, t_cell board[X][X])
{
	t_cell	*cell;
	int		i;
	uint8_t	moved;

	reset_merge(board);
	i = 0;
	moved = 0;
	while ((cell = get_cell(board, i, ret)) != NULLPTR)
	{
		i++;
		if (cell->value == 0)
			continue ;
		move_cell(cell, ret, board, &moved);
	}
	if (moved)
		grid_make_random(board);
}
