/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_empty_cell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:41:28 by apilate           #+#    #+#             */
/*   Updated: 2015/03/01 12:41:29 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "g2048.h"

uint8_t	grid_empty_cell(t_cell board[X][X])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < X)
	{
		while (y < X)
		{
			if (board[x][y].value == 0)
				return (1);
			++y;
		}
		y = 0;
		++x;
	}
	return (0);
}
