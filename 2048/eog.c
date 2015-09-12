/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eog.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:17:37 by ajung             #+#    #+#             */
/*   Updated: 2015/09/12 19:29:47 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g2048.h"
#include <libft.h>

void		eog(char *str, t_cell board[X][X])
{
	t_draw	w;

	endwin();
	refresh();
	clear();
	initscr();
	getmaxyx(stdscr, w.cols, w.lines);
	mvwaddstr(stdscr, w.cols / 3, w.lines / 3, str);
	mvwaddstr(stdscr, (w.cols / 3) + 3, w.lines / 3, "You scored :");
	mvwaddstr(stdscr, (w.cols / 3) + 5, w.lines / 3, ft_itoa(get_score(board)));
	mvwaddstr(stdscr, (w.cols / 3) + 7, w.lines / 3, "Press any key to exit !");
	refresh();
}
