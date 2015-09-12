/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g2048.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:52:06 by apilate           #+#    #+#             */
/*   Updated: 2015/08/24 04:30:58 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G2048_H
# define G2048_H

# include <stdint.h>
# include <ncurses.h>

# define BOARDSIZE 4

# if BOARDSIZE < 4 || BOARDSIZE > 4
#  error "Board size incorrect"
# endif

# define X BOARDSIZE

# define NULLPTR (void*)0

enum			e_const
{
	WIN_VALUE = 256
};

enum			e_direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	EXIT,
	CONTINUE,
};

typedef struct	s_cell
{
	uintmax_t	value;
	uint8_t		x;
	uint8_t		y;
	uint8_t		merged;
	int			drawed;
}				t_cell;

typedef struct	s_window
{
	int	width;
	int	h;
	int	cols;
	int	lines;
	int	x;
	int	y;
	int	color;
	int	drawed;
}				t_draw;

void			next_move(int ret, t_cell board[X][X]);
int				next_position(uint8_t *x, uint8_t *y,
							enum e_direction direction);
uint8_t			grid_empty_cell(t_cell board[X][X]);
void			grid_make_random(t_cell board[X][X]);
uint8_t			grid_avaliable_moves(t_cell board[X][X]);
t_cell			*next_cell(t_cell board[X][X], uint8_t x, uint8_t y
										, int ret);
t_cell			*get_cell(t_cell board[X][X], int i, int ret);
t_cell			*farthest_cell(t_cell board[X][X], uint8_t x,
								uint8_t y, int ret);
int				get_score(t_cell board[X][X]);
int				ncurses(t_draw w, WINDOW *win[X][X],
							t_cell b[X][X]);
int				checkwin(t_cell	board[X][X]);
void			draw(t_draw w, WINDOW *win[X][X], t_cell b[X][X]);
void			eog(char *str, t_cell board[X][X]);
void			scrinit(t_draw w, WINDOW *win[X][X], t_cell b[X][X]);
void			scrrefresh(t_draw w, WINDOW *win[X][X], t_cell b[X][X]);
void			tab(t_draw w, WINDOW *win[X][X], t_cell b[X][X]);
#endif
