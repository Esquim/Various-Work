/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:19:52 by apilate           #+#    #+#             */
/*   Updated: 2013/12/02 14:29:55 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	char	d;

	d = (char)c;
	p = (char*)s;
	while (*p)
	{
		if (*p == d)
		{
			return (p);
		}
		p++;
	}
	if (*p == d)
	{
		return (p);
	}
	return (NULL);
}
