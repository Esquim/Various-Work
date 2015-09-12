/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handler_uint.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 14:48:04 by apilate           #+#    #+#             */
/*   Updated: 2014/05/03 14:45:35 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>

int				ft_printf_uintlength(unsigned long long int n,
	int nbase)
{
	int				length;

	length = 0;
	if (n == 0)
		length = 1;
	while (n > 0)
	{
		n /= nbase;
		length++;
	}
	return (length);
}

void			ft_printf_putuint(unsigned long long int n,
	t_ftprintf_fmt_spec *spec,
	char *base, int nbase)
{
	unsigned int			nb;

	if (n > 0)
	{
		nb = n % nbase;
		ft_printf_putuint(n / nbase, spec, base, nbase);
		ft_putchar(base[nb]);
	}
}

int				ft_printf_uint_prefix(t_ftprintf_fmt_spec *spec)
{
	int				size;

	size = 2;
	if (spec->specifier == 'o')
	{
		ft_putchar('0');
		size = 1;
	}
	else if (spec->specifier == 'x' || spec->specifier == 'p')
		ft_putstr("0x");
	else if (spec->specifier == 'X')
		ft_putstr("0X");
	return (size);
}

int				ft_printf_uint_base(va_list args,
	t_ftprintf_fmt_spec *spec,
	char **base, int param)
{
	int				nbase;

	*base = "0123456789abcdef";
	nbase = param;
	if (spec->specifier == 'X')
		*base = "0123456789ABCDEF";
	else if (spec->specifier == 'U')
	{
		*base = va_arg(args, char *);
		nbase = ft_strlen(*base);
	}
	if (ft_checkbase(*base) == 0)
		return (0);
	return (nbase);
}

int				ft_printf_uint_handler(va_list args,
	t_ftprintf_fmt_spec *spec,
	int param)
{
	unsigned long long int	n;
	int						length;
	int						size;
	char					*base;
	int						nbase;

	n = ft_printf_unsigned_value(args, spec);
	nbase = ft_printf_uint_base(args, spec, &base, param);
	if (nbase == 0)
		return (0);
	length = ft_printf_uintlength(n, nbase);
	size = length;
	if ((n > 0 && (spec->flags & FT_PRINTF_FLAG_PREFIX))
		|| spec->specifier == 'p')
		size += ft_printf_uint_prefix(spec);
	if ((spec->flags & FT_PRINTF_FLAG_LJUSTIFY) == 0)
		ft_fillspace((spec->flags & FT_PRINTF_FLAG_LPAD) ? '0' : ' ',
			spec->width - size);
	ft_printf_putuint(n, spec, base, nbase);
	if (spec->flags & FT_PRINTF_FLAG_LJUSTIFY)
		ft_fillspace((spec->flags & FT_PRINTF_FLAG_LPAD) ? '0' : ' ',
			spec->width - size);
	return (MAX(size, spec->width));
}
