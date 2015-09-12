/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_make_random.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:41:17 by apilate           #+#    #+#             */
/*   Updated: 2015/03/01 12:41:18 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "g2048.h"

void	grid_make_random(t_cell board[X][X])
{
	uint8_t	x;
	uint8_t	y;

	if (!(grid_empty_cell(board)))
		return ;
	while (1)
	{
		x = rand() % 4;
		y = rand() % 4;
		if (board[x][y].value == 0)
		{
			board[x][y].value = rand() % 10 == 5 ? 4 : 2;
			board[x][y].x = x;
			board[x][y].y = y;
			return ;
		}
	}
}
