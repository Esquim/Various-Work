/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handler_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 14:48:04 by apilate           #+#    #+#             */
/*   Updated: 2013/12/24 15:13:23 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <libft.h>

int	ft_printf_char_handler(va_list args, t_ftprintf_fmt_spec *spec,
	int param)
{
	int		i;

	(void)param;
	if ((spec->flags & FT_PRINTF_FLAG_LJUSTIFY) == 0)
	{
		i = 0;
		while (++i < spec->width)
			ft_putchar(' ');
	}
	ft_putchar(va_arg(args, int));
	if (spec->flags & FT_PRINTF_FLAG_LJUSTIFY)
	{
		i = 0;
		while (++i < spec->width)
			ft_putchar(' ');
	}
	if (spec->width)
		return (spec->width + 1);
	return (1);
}
