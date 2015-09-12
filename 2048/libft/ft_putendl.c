/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:35:24 by apilate           #+#    #+#             */
/*   Updated: 2013/12/13 15:50:36 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

int		ft_putendl(char const *s)
{
	int		toreturn;
	int		tmp;

	toreturn = 0;
	if (s == NULL)
		return (-1);
	tmp = ft_putstr(s);
	if (tmp == -1)
		return (-1);
	toreturn += tmp;
	tmp = ft_putchar('\n');
	if (tmp == -1)
		return (-1);
	toreturn += tmp;
	return (toreturn);
}
