/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handler_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 14:48:04 by apilate           #+#    #+#             */
/*   Updated: 2014/05/03 14:45:16 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <libft.h>

int		ft_printf_intsize(long long int n, t_ftprintf_fmt_spec *spec)
{
	int		size;

	(void)spec;
	size = 0;
	if (n == 0)
		size = 1;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void	ft_printf_putint_n(long long int n)
{
	int		nb;

	if (n != 0)
	{
		nb = n % 10;
		ft_printf_putint_n(n / 10);
		if (nb < 0)
			nb = -nb;
		ft_putchar('0' + nb);
	}
}

void	ft_printf_putint(long long int n)
{
	if (n == 0)
		ft_putchar('0');
	else
		ft_printf_putint_n(n);
}

void	ft_printf_intsign(long long int n,
	t_ftprintf_fmt_spec *spec)
{
	if (n < 0)
		ft_putchar(spec->flags & FT_PRINTF_FLAG_NOSIGN ? ' ' : '-');
	else if (spec->flags & FT_PRINTF_FLAG_SIGN)
		ft_putchar(spec->flags & FT_PRINTF_FLAG_NOSIGN ? ' ' : '+');
	else if (spec->flags & FT_PRINTF_FLAG_NOSIGN)
		ft_putchar(' ');
}

int		ft_printf_int_handler(va_list args, t_ftprintf_fmt_spec *spec,
	int param)
{
	long long int	n;
	int				length;
	int				size;

	n = ft_printf_signed_value(args, spec);
	if (n == 0 && spec->precision == 0 && param != -42)
		return (0);
	length = ft_printf_intsize(n, spec);
	size = length;
	if (spec->precision > 0)
		size += spec->precision;
	if (spec->flags & (FT_PRINTF_FLAG_NOSIGN | FT_PRINTF_FLAG_SIGN) || n < 0)
		size++;
	if (spec->flags & FT_PRINTF_FLAG_LPAD)
		ft_printf_intsign(n, spec);
	if ((spec->flags & FT_PRINTF_FLAG_LJUSTIFY) == 0)
		ft_fillspace((spec->flags & FT_PRINTF_FLAG_LPAD) ? '0' : ' ',
			spec->width - size);
	if ((spec->flags & FT_PRINTF_FLAG_LPAD) == 0)
		ft_printf_intsign(n, spec);
	ft_fillspace('0', spec->precision - length);
	ft_printf_putint(n);
	if (spec->flags & FT_PRINTF_FLAG_LJUSTIFY)
		ft_fillspace(' ', spec->width - size);
	return (MAX(size, spec->width));
}
