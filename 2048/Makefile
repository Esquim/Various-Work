# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajung <ajung@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/19 14:58:12 by apilate           #+#    #+#              #
#    Updated: 2015/03/01 21:32:31 by ajung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= game_2048

CC		= clang

RM		= rm -rf

CFLAGS	= -g -Ilibft/includes -Wall -Wextra -Werror -Ofast

LDFLAGS	= -Llibft/ -g -lft -lncurses

SRCS =	main.c next_move.c next_position.c grid_avaliable_moves.c \
		grid_empty_cell.c grid_make_random.c get_cell.c next_cell.c \
		farthest_cell.c get_score.c ncurses.c tab.c scrinit.c draw.c \
		scrrefresh.c eog.c checkwin.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): libft/libft.a $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

libft/libft.a:
	@make -C libft/

clean:
	$(RM) $(OBJS)
	@make -C libft/ clean

fclean: clean
	$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all re clean fclean
