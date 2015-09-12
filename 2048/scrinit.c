/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:42:29 by apilate           #+#    #+#             */
/*   Updated: 2015/03/01 21:12:30 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g2048.h"

void	scrinit(t_draw w, WINDOW *win[X][X], t_cell b[X][X])
{
	initscr();
	refresh();
	curs_set(0);
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(8, COLOR_BLUE, COLOR_BLACK);
	init_pair(16, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(32, COLOR_RED, COLOR_BLACK);
	init_pair(64, COLOR_CYAN, COLOR_BLACK);
	init_pair(128, COLOR_WHITE, COLOR_BLACK);
	init_pair(256, COLOR_BLACK, COLOR_GREEN);
	init_pair(512, COLOR_BLACK, COLOR_YELLOW);
	init_pair(1024, COLOR_BLACK, COLOR_BLUE);
	init_pair(2048, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(0, COLOR_BLACK, COLOR_WHITE);
	w.x = 0;
	w.y = 0;
	w.cols = COLS;
	w.lines = LINES;
	tab(w, win, b);
}
