/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:09:30 by apilate           #+#    #+#             */
/*   Updated: 2015/03/01 18:09:30 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g2048.h"

int get_score(t_cell board[X][X])
{
	int	x;
	int	y;
	int	score;

	x = 0;
	y = 0;
	score = 0;
	while (x < X)
	{
		while (y < X)
		{
			score += board[x][y].value;
			++y;
		}
		y = 0;
		++x;
	}
	return (score);
}
