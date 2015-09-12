/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:42:51 by apilate           #+#    #+#             */
/*   Updated: 2015/03/01 21:28:41 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "g2048.h"

void	draw(t_draw w, WINDOW *win[X][X], t_cell b[X][X])
{
	win[w.x][w.y] = newwin(w.h, w.width, w.h * w.y, w.width * w.x);
	if (b[w.x][w.y].merged == 0 && b[w.x][w.y].value <= 2048)
		wattron(win[w.x][w.y], COLOR_PAIR(b[w.x][w.y].value));
	else
		wattron(win[w.x][w.y], COLOR_PAIR(0) | A_BOLD);
	box(win[w.x][w.y], 0, 0);
	mvwaddstr(win[w.x][w.y], w.h / 2, w.width / 2, ft_itoa(b[w.x][w.y].value));
	wattroff(win[w.x][w.y], COLOR_PAIR(1));
	wrefresh(win[w.x][w.y]);
}
