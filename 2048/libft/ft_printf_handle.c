/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 14:45:46 by apilate           #+#    #+#             */
/*   Updated: 2013/12/24 15:12:33 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>

int	ft_printf_flags(const char **fmt)
{
	int		flags;
	char	c;

	flags = 0;
	while ((c = *(*fmt)) &&
		(c == '-' || c == '+' || c == ' ' || c == '#' || c == '0'))
	{
		if (c == '-')
			flags |= FT_PRINTF_FLAG_LJUSTIFY;
		else if (c == '+')
			flags |= FT_PRINTF_FLAG_SIGN;
		else if (c == ' ')
			flags |= FT_PRINTF_FLAG_NOSIGN;
		else if (c == '#')
			flags |= FT_PRINTF_FLAG_PREFIX;
		else if (c == '0')
			flags |= FT_PRINTF_FLAG_LPAD;
		(*fmt)++;
	}
	return (flags);
}

int	ft_printf_width(const char **fmt, va_list args)
{
	int		width;
	char	c;

	width = 0;
	while ((c = *(*fmt)) && c >= '0' && c <= '9')
	{
		width *= 10;
		width += c - '0';
		(*fmt)++;
	}
	if (c == '*')
	{
		width = va_arg(args, int);
		(*fmt)++;
	}
	return (width);
}

int	ft_printf_precision(const char **fmt, va_list args)
{
	int		precision;
	char	c;

	precision = -1;
	if ((c = *(*fmt))
		&& c == '.')
	{
		(*fmt)++;
		precision = 0;
		while ((c = *(*fmt))
			&& c >= '0' && c <= '9')
		{
			precision *= 10;
			precision += c - '0';
			(*fmt)++;
		}
		if (c == '*')
		{
			precision = va_arg(args, int);
			(*fmt)++;
		}
	}
	return (precision);
}

int	ft_printf_length(const char **fmt, va_list args)
{
	char	c;

	(void)args;
	if ((c = *(*fmt)) == 'h')
	{
		if ((c = *(++(*fmt))) == 'h')
		{
			(*fmt)++;
			return (FT_PRINTF_LENGTH_HH);
		}
		else
			return (FT_PRINTF_LENGTH_H);
	}
	else if (c == 'l')
	{
		if ((c = *(++(*fmt))) == 'l')
		{
			(*fmt)++;
			return (FT_PRINTF_LENGTH_LL);
		}
		else
			return (FT_PRINTF_LENGTH_L);
	}
	return (FT_PRINTF_LENGTH_NONE);
}
