/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:35:59 by apilate           #+#    #+#             */
/*   Updated: 2013/12/13 15:50:04 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

int		ft_putendl_fd(char const *s, int fd)
{
	int		toreturn;
	int		tmp;

	toreturn = 0;
	if (s == NULL)
		return (-1);
	tmp = ft_putstr_fd(s, fd);
	if (tmp == -1)
		return (-1);
	toreturn += tmp;
	tmp = ft_putchar_fd('\n', fd);
	if (tmp == -1)
		return (-1);
	toreturn += tmp;
	return (toreturn);
}
