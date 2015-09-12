/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 14:46:40 by apilate           #+#    #+#             */
/*   Updated: 2014/04/28 15:05:56 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void				ft_printf_handlers_chars(t_ftprintf_handler *handlers)
{
	handlers[0].c = 'c';
	handlers[0].handler = &ft_printf_char_handler;
	handlers[0].param = 0;
	handlers[1].c = 's';
	handlers[1].handler = &ft_printf_string_handler;
	handlers[1].param = 0;
	handlers[2].c = 'S';
	handlers[2].handler = &ft_printf_string_handler;
	handlers[2].param = 1;
}

void				ft_printf_handlers_int(t_ftprintf_handler *handlers)
{
	handlers[3].c = 'd';
	handlers[3].handler = &ft_printf_int_handler;
	handlers[3].param = 10;
	handlers[4].c = 'i';
	handlers[4].handler = &ft_printf_int_handler;
	handlers[4].param = 10;
}

void				ft_printf_handlers_uint(t_ftprintf_handler *handlers)
{
	handlers[5].c = 'u';
	handlers[5].handler = &ft_printf_uint_handler;
	handlers[5].param = 10;
	handlers[6].c = 'U';
	handlers[6].handler = &ft_printf_uint_handler;
	handlers[6].param = 0;
	handlers[7].c = 'b';
	handlers[7].handler = &ft_printf_uint_handler;
	handlers[7].param = 2;
	handlers[8].c = 'o';
	handlers[8].handler = &ft_printf_uint_handler;
	handlers[8].param = 8;
	handlers[9].c = 'x';
	handlers[9].handler = &ft_printf_uint_handler;
	handlers[9].param = 16;
	handlers[10].c = 'X';
	handlers[10].handler = &ft_printf_uint_handler;
	handlers[10].param = 16;
	handlers[11].c = 'p';
	handlers[11].handler = &ft_printf_uint_handler;
	handlers[11].param = 16;
}

t_ftprintf_handler	*ft_printf_handlers(void)
{
	t_ftprintf_handler	*handlers;

	handlers = malloc(13 * sizeof(t_ftprintf_handler));
	ft_printf_handlers_chars(handlers);
	ft_printf_handlers_int(handlers);
	ft_printf_handlers_uint(handlers);
	handlers[12].c = '%';
	handlers[12].handler = &ft_printf_percent_handler;
	handlers[12].param = 0;
	return (handlers);
}
