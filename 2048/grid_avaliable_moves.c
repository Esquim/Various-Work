/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_avaliable_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:44:46 by apilate           #+#    #+#             */
/*   Updated: 2015/03/01 12:44:47 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "g2048.h"

static uint8_t	cell_avaliable_move(t_cell board[X][X], t_cell *cell)
{
	t_cell				*close_cell;
	enum e_direction	direction;

	direction = 0;
	while (direction != 4)
	{
		close_cell = next_cell(board, cell->x, cell->y, direction);
		if (close_cell != NULLPTR && close_cell != cell)
		{
			if (close_cell->value == cell->value)
				return (1);
		}
		++direction;
	}
	return (0);
}

uint8_t			grid_avaliable_moves(t_cell board[X][X])
{
	uint8_t	x;
	uint8_t	y;

	if (grid_empty_cell(board))
		return (1);
	x = 0;
	y = 0;
	while (x < X)
	{
		while (y < X)
		{
			if (cell_avaliable_move(board, &board[x][y]))
				return (1);
			++y;
		}
		y = 0;
		++x;
	}
	return (0);
}
