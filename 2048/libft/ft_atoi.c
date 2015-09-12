/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:30:21 by apilate           #+#    #+#             */
/*   Updated: 2014/05/04 18:05:12 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_isspace(char n)
{
	return (n == '\t' || n == '\v' || n == '\f'
	|| n == '\n' || n == '\r' || n == ' ');
}

int			ft_atoi(const char *str)
{
	int		result;
	int		pol;

	pol = 0;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == 0)
		return (result);
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		pol = 1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	if (pol)
		result -= result * 2;
	return (result);
}
