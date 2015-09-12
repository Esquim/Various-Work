/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:42:37 by apilate           #+#    #+#             */
/*   Updated: 2015/03/01 21:29:46 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g2048.h"

void	tab(t_draw w, WINDOW *win[X][X], t_cell b[X][X])
{
	w.width = w.cols / X;
	w.h = w.lines / X;
	while (w.y != X)
	{
		if (b[w.x][w.y].drawed == 1)
			delwin(win[w.x][w.y]);
		draw(w, win, b);
		b[w.x][w.y].drawed = 1;
		if (w.x == X - 1)
		{
			w.x = 0;
			w.y++;
		}
		else
			++w.x;
	}
}
