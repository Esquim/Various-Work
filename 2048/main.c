/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:46:30 by apilate           #+#    #+#             */
/*   Updated: 2015/08/22 13:46:39 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <unistd.h>
#include <libft.h>
#include "g2048.h"

static inline int	is_power_of_two(uint32_t x)
{
	return ((x != 0) && !(x & (x - 1)));
}

static void			init_board(t_cell board[X][X])
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	while (x < X)
	{
		while (y < X)
		{
			board[x][y].value = 0;
			board[x][y].x = x;
			board[x][y].y = y;
			++y;
		}
		y = 0;
		++x;
	}
	grid_make_random(board);
	grid_make_random(board);
}

static int			loop(t_cell board[X][X], WINDOW *win[X][X], t_draw w)
{
	int				ret;

	ret = ncurses(w, win, board);
	if (ret == EXIT)
	{
		eog("Game exited.", board);
		return (EXIT);
	}
	next_move(ret, board);
	if (!(grid_avaliable_moves(board)))
	{
		eog("Lost!", board);
		return (EXIT);
	}
	scrrefresh(w, win, board);
	if (checkwin(board))
		return (EXIT);
	return (CONTINUE);
}

int					main(void)
{
	t_cell			board[X][X];
	WINDOW			*win[X][X];
	t_draw			w;

	w.color = 1;
	srand(time(NULL));
	if (WIN_VALUE <= 0 || is_power_of_two((uint32_t)WIN_VALUE) == 0)
	{
		ft_printf("Win value is not a power of two!\n");
		return (1);
	}
	init_board(board);
	scrinit(w, win, board);
	while (1)
	{
		if (loop(board, win, w) == EXIT)
			break ;
	}
	refresh();
	getch();
	endwin();
	return (0);
}
