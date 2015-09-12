/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:29:54 by ajung             #+#    #+#             */
/*   Updated: 2015/08/22 13:48:26 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g2048.h"

int		ncurses(t_draw w, WINDOW *win[X][X], t_cell b[X][X])
{
	int	key;

	key = 0;
	while (key != 27)
	{
		key = getch();
		if (key == KEY_RESIZE)
		{
			endwin();
			refresh();
			clear();
			getmaxyx(stdscr, w.cols, w.lines);
			scrinit(w, win, b);
		}
		else if (key == KEY_UP)
			return (UP);
		else if (key == KEY_DOWN)
			return (DOWN);
		else if (key == KEY_LEFT)
			return (LEFT);
		else if (key == KEY_RIGHT)
			return (RIGHT);
	}
	endwin();
	return (EXIT);
}
