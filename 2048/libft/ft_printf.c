/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 14:43:36 by apilate           #+#    #+#             */
/*   Updated: 2014/05/04 17:48:35 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <libft.h>

int			ft_printf_percent_handler(va_list args,
	t_ftprintf_fmt_spec *spec,
	int format)
{
	(void)args;
	(void)spec;
	(void)format;
	ft_putchar('%');
	return (1);
}

int			ft_printf_handle_flag(t_ftprintf_handler *handlers,
	const char **fmt, va_list args,
	t_ftprintf_fmt_spec *spec)
{
	int			i;

	(void)fmt;
	i = 0;
	while (i < FT_PRINTF_HANDLERS)
	{
		if (spec->specifier == handlers[i].c)
			return (handlers[i].handler(args, spec, handlers[i].param));
		i++;
	}
	return (0);
}

int			ft_printf_handle(t_ftprintf_handler *handlers,
	const char **fmt, va_list args)
{
	t_ftprintf_fmt_spec	spec;
	const char			*start;
	int					size;

	start = *fmt - 1;
	spec.flags = ft_printf_flags(fmt);
	spec.width = ft_printf_width(fmt, args);
	spec.precision = ft_printf_precision(fmt, args);
	spec.length = ft_printf_length(fmt, args);
	spec.specifier = *(*fmt);
	if (spec.specifier == 0)
		return (0);
	(*fmt)++;
	size = ft_printf_handle_flag(handlers, fmt, args, &spec);
	if (size > 0)
		return (size);
	size = *fmt - start;
	while (start < *fmt)
		ft_putchar(*start++);
	return (size);
}

int			ft_vprintf(const char *fmt, va_list args)
{
	int					counter;
	t_ftprintf_handler	*handlers;

	counter = 0;
	handlers = ft_printf_handlers();
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_putchar(*fmt++);
			counter++;
		}
		else
		{
			fmt++;
			counter += ft_printf_handle(handlers, &fmt, args);
		}
	}
	free(handlers);
	return (counter);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			result;

	result = 0;
	if (fmt != NULL)
	{
		va_start(args, fmt);
		result = ft_vprintf(fmt, args);
		va_end(args);
	}
	return (result);
}
