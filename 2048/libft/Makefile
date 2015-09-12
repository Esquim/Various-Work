# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apilate <apilate@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/08/03 15:34:27 by apilate           #+#    #+#              #
#    Updated: 2015/02/28 13:10:38 by apilate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g -Iincludes

NAME = libft.a

LIBSRCS =	ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isupper.c \
			ft_islower.c \
			ft_itoa.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strrev.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_swap.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c \
			ft_printf.c \
			ft_printf_handle.c \
			ft_printf_handler_char.c \
			ft_printf_handler_int.c \
			ft_printf_handler_string.c \
			ft_printf_handler_uint.c \
			ft_printf_util.c \
			ft_printf_handlers.c \
			ft_fillspace.c \
			ft_checkbase.c \
			ft_errno.c

MALLOC_SRC_COMMON		=	malloc/src/entry/api.c			\
				malloc/src/entry/context.c		\
				malloc/src/log.c			\
				malloc/src/conf/init.c			\
				malloc/src/algo/init.c			\


MALLOC_SRC_FIRST_FIT		=	malloc/src/algo/first_fit/malloc.c	\
				malloc/src/algo/first_fit/realloc.c	\
				malloc/src/algo/first_fit/free.c	\
				malloc/src/algo/first_fit/utils.c	\
				malloc/src/algo/first_fit/show.c	\
				malloc/src/algo/first_fit/init.c	\

MALLOC_SRC_BEST_FIT		=	malloc/src/algo/best_fit/malloc.c	\
				malloc/src/algo/best_fit/realloc.c	\
				malloc/src/algo/best_fit/free.c	\
				malloc/src/algo/best_fit/utils.c	\
				malloc/src/algo/best_fit/show.c	\
				malloc/src/algo/best_fit/init.c	\


MALLOC_SRCS			=	$(MALLOC_SRC_COMMON)			\
				$(MALLOC_SRC_FIRST_FIT)		\
				$(MALLOC_SRC_BEST_FIT)			\

LIBOBJS	= $(LIBSRCS:.c=.o)
MALLOC_OBJS	=	$(MALLOC_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(LIBOBJS)
	@make -C malloc/
	@ar rc $(NAME) $(LIBOBJS) $(MALLOC_OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@make -C malloc/ clean
	@$(RM) $(LIBOBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
