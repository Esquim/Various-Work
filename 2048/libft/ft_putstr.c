/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/18 15:00:07 by apilate           #+#    #+#             */
/*   Updated: 2013/12/13 15:50:14 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

int		ft_putstr(const char *s)
{
	int		toreturn;
	int		tmp;

	tmp = 0;
	toreturn = 0;
	if (s == NULL)
		return (-1);
	while (*s != '\0')
	{
		tmp = ft_putchar(*s);
		if (tmp == -1)
			return (-1);
		toreturn += tmp;
		s++;
	}
	return (toreturn);
}
