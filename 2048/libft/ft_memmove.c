/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:03:49 by apilate           #+#    #+#             */
/*   Updated: 2013/11/20 16:03:50 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*begin;

	begin = s1;
	if (s2 < s1)
	{
		while (n)
		{
			((char *)s1)[n - 1] = ((char *)s2)[n - 1];
			n--;
		}
	}
	else
	{
		while (n--)
			*((char *)s1++) = *((char *)s2++);
	}
	return (begin);
}
