/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handler_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 14:48:04 by apilate           #+#    #+#             */
/*   Updated: 2013/12/27 15:59:09 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <libft.h>

int		ft_printf_strlen(unsigned char *str, int param)
{
	int		length;

	length = 0;
	if (*str == 0)
		return (1);
	while (*str)
	{
		if ((*str >= ' ' && *str <= '~') || param == 0)
			length++;
		else
			length += 4;
		str++;
	}
	return (length);
}

int		ft_printf_showstr(unsigned char *str,
	t_ftprintf_fmt_spec *spec,
	int param)
{
	int		length;
	int		precision;

	length = 0;
	precision = spec->precision;
	while (*str && (precision == -1 || precision > 0))
	{
		if ((*str >= ' ' && *str <= '~') || param == 0)
			ft_putchar(*str);
		else
		{
			ft_putchar('\\');
			ft_putchar('0' + ((*str / 64) % 8));
			ft_putchar('0' + ((*str / 8) % 8));
			ft_putchar('0' + (*str % 8));
		}
		if (precision > 0)
			precision--;
		str++;
	}
	return (length);
}

int		ft_printf_nullstr(void)
{
	ft_putstr("(null)");
	return (6);
}

int		ft_printf_string_handler(va_list args,
	t_ftprintf_fmt_spec *spec,
	int param)
{
	unsigned char	*str;
	int				length;
	int				i;

	str = va_arg(args, unsigned char *);
	if (str == NULL)
		return (ft_printf_nullstr());
	length = ft_printf_strlen(str, param);
	if (spec->precision >= 0)
		length = MIN(length, spec->precision);
	if ((spec->flags & FT_PRINTF_FLAG_LJUSTIFY) == 0)
	{
		i = -1;
		while (++i < (spec->width - length))
			ft_putchar(' ');
	}
	ft_printf_showstr(str, spec, param);
	if (spec->flags & FT_PRINTF_FLAG_LJUSTIFY)
	{
		i = -1;
		while (++i < (spec->width - length))
			ft_putchar(' ');
	}
	return (MAX(length, spec->width));
}
