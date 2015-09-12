/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:35:51 by apilate           #+#    #+#             */
/*   Updated: 2013/12/13 15:50:21 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

int		ft_putstr_fd(char const *s, int fd)
{
	int		toreturn;
	int		tmp;

	toreturn = 0;
	tmp = 0;
	if (s == NULL)
		return (-1);
	while (*s != '\0')
	{
		tmp = ft_putchar_fd(*s, fd);
		if (tmp == -1)
			return (-1);
		toreturn += tmp;
		s++;
	}
	return (toreturn);
}
