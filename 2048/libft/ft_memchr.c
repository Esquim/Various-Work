/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:27:59 by apilate           #+#    #+#             */
/*   Updated: 2013/12/02 14:32:10 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	tofind;
	size_t			i;

	i = 0;
	tofind = (unsigned char)c;
	while (i < n)
	{
		if (*(unsigned char*)s == tofind)
		{
			return ((void*)s);
		}
		s++;
		i++;
	}
	return (NULL);
}
