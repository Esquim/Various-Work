/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkwin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:32:16 by ajung             #+#    #+#             */
/*   Updated: 2015/09/12 19:29:23 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g2048.h"

int		checkwin(t_cell board[X][X])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < X)
	{
		if (board[x][y].value == WIN_VALUE)
		{
			eog("You win !", board);
			return (1);
		}
		x++;
		if (x == X)
		{
			x = 0;
			++y;
		}
	}
	return (0);
}
