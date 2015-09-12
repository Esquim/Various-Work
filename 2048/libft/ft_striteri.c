/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:33:54 by apilate           #+#    #+#             */
/*   Updated: 2013/12/13 14:40:01 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*str;

	if (s == NULL || f == NULL)
		return ;
	str = s;
	while (*str)
	{
		f(str - s, str);
		str++;
	}
}
