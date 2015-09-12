/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farthest_cell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 15:47:27 by apilate           #+#    #+#             */
/*   Updated: 2015/03/01 15:47:28 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g2048.h"

t_cell	*farthest_cell(t_cell board[X][X], uint8_t x, uint8_t y, int ret)
{
	t_cell	*previous;
	uint8_t	changed;

	previous = &board[x][y];
	changed = next_position(&x, &y, ret);
	while (changed && x < X && y < X && board[x][y].value == 0)
	{
		previous = &board[x][y];
		changed = next_position(&x, &y, ret);
	}
	return (previous);
}
