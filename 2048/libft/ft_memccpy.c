/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:49:39 by apilate           #+#    #+#             */
/*   Updated: 2014/05/03 14:44:22 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*dest;
	char			*src;
	unsigned char	tofind;
	size_t			i;

	i = 0;
	tofind = (unsigned char)c;
	dest = (char*)s1;
	src = (char*)s2;
	while (i < n)
	{
		if ((dest[i] = src[i]) == tofind)
		{
			return (dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
