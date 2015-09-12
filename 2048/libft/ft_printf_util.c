/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 14:48:04 by apilate           #+#    #+#             */
/*   Updated: 2014/04/28 15:06:01 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>

unsigned long long int		ft_printf_unsigned_value(va_list args,
	t_ftprintf_fmt_spec *spec)
{
	unsigned long long int	n;

	if (spec->length == FT_PRINTF_LENGTH_L)
		n = va_arg(args, unsigned long int);
	else if (spec->length == FT_PRINTF_LENGTH_LL)
		n = va_arg(args, unsigned long long int);
	else
		n = va_arg(args, unsigned int);
	return (n);
}

long long int				ft_printf_signed_value(va_list args,
	t_ftprintf_fmt_spec *spec)
{
	long long int			n;

	if (spec->length == FT_PRINTF_LENGTH_L)
		n = va_arg(args, long int);
	else if (spec->length == FT_PRINTF_LENGTH_LL)
		n = va_arg(args, long long int);
	else
		n = va_arg(args, int);
	return (n);
}
