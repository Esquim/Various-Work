/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrrefresh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:34:52 by ajung             #+#    #+#             */
/*   Updated: 2015/03/01 21:12:42 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g2048.h"

void	scrrefresh(t_draw w, WINDOW *win[X][X], t_cell b[X][X])
{
	endwin();
	refresh();
	clear();
	getmaxyx(stdscr, w.cols, w.lines);
	scrinit(w, win, b);
}
