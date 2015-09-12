/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 15:47:12 by apilate           #+#    #+#             */
/*   Updated: 2015/03/01 15:47:13 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g2048.h"

t_cell	*get_cell(t_cell board[X][X], int i, int ret)
{
	if (i >= (X * X))
		return (NULLPTR);
	if (ret == DOWN)
		return (&board[i / X][(X - i % X) - 1]);
	else if (ret == RIGHT)
		return (&board[(X - i / X) - 1][i % X]);
	else
		return (&board[i / X][i % X]);
}
