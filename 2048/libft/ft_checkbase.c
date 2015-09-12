/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 15:26:09 by apilate           #+#    #+#             */
/*   Updated: 2013/12/27 15:57:15 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	tmp_strchr(char *str, char c)
{
	int		idx;
	char	*tmp;

	idx = -1;
	tmp = str;
	while (*tmp && idx < 0)
	{
		if (*tmp == c)
			idx = tmp - str;
		tmp++;
	}
	return (idx);
}

int			ft_checkbase(char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (tmp_strchr(base, base[i]) != i)
			return (0);
		i++;
	}
	return (1);
}
