/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:19:59 by apilate           #+#    #+#             */
/*   Updated: 2013/12/02 14:30:26 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*found;
	char	*p;
	char	d;

	d = (char)c;
	p = (char*)s;
	found = NULL;
	while (*p)
	{
		if (*p == d)
		{
			found = p;
		}
		p++;
	}
	if (*p == d)
	{
		found = p;
	}
	return (found);
}
