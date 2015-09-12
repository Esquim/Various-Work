/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:03:36 by apilate           #+#    #+#             */
/*   Updated: 2013/11/20 15:03:37 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*dest;
	char	*src;
	size_t	i;

	i = 0;
	dest = (char*)s1;
	src = (char*)s2;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (s1);
}
