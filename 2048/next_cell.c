/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_cell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 15:47:35 by apilate           #+#    #+#             */
/*   Updated: 2015/03/01 15:47:36 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g2048.h"

t_cell	*next_cell(t_cell board[X][X], uint8_t x, uint8_t y, int ret)
{
	if (next_position(&x, &y, ret))
	{
		if (x < X && y < X)
			return (&board[x][y]);
	}
	return (NULLPTR);
}
