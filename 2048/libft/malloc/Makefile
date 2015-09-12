# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apilate <apilate@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/28 15:30:02 by apilate           #+#    #+#              #
#    Updated: 2015/02/28 13:09:59 by apilate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compile/Link flags
FLAGS			:=	-Wall -Wextra -Werror -fPIC -D_REENTRANT
FLAGS			+=	-O3 -Wno-deprecated-declarations
ifeq ($(CC),clang)
FLAGS			+=	-flto
endif

CFLAGS			:=	$(FLAGS) -I include -I../includes/
LDFLAGS			:=	$(FLAGS) -shared
LIBS			:=	-lpthread

# Sources

SRC_COMMON		=	src/entry/api.c			\
				src/entry/context.c		\
				src/log.c			\
				src/conf/init.c			\
				src/algo/init.c			\


SRC_FIRST_FIT		=	src/algo/first_fit/malloc.c	\
				src/algo/first_fit/realloc.c	\
				src/algo/first_fit/free.c	\
				src/algo/first_fit/utils.c	\
				src/algo/first_fit/show.c	\
				src/algo/first_fit/init.c	\

SRC_BEST_FIT		=	src/algo/best_fit/malloc.c	\
				src/algo/best_fit/realloc.c	\
				src/algo/best_fit/free.c	\
				src/algo/best_fit/utils.c	\
				src/algo/best_fit/show.c	\
				src/algo/best_fit/init.c	\


SRCS			=	$(SRC_COMMON)			\
				$(SRC_FIRST_FIT)		\
				$(SRC_BEST_FIT)			\

INCS			:=	include/ft_malloc.h		\
				include/struct_malloc.h		\

OBJS			:=	$(SRCS:.c=.o)

# Rules
all:			$(OBJS)
.PHONY:			all

%.o:			%.c
			@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS):		$(INCS)

clean:
			@rm -f $(OBJS)
.PHONY:			clean

re:			clean all
.PHONY:			re
