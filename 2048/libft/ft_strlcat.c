/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:52:50 by apilate           #+#    #+#             */
/*   Updated: 2013/11/22 13:52:51 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dlen;
	size_t		n;
	char		*dest;
	const char	*ssrc;

	dest = dst;
	ssrc = src;
	n = size;
	while (n-- != 0 && *dest != '\0')
		dest++;
	dlen = dest - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(ssrc));
	while (*ssrc != '\0')
	{
		if (n != 1)
		{
			*dest++ = *ssrc;
			n--;
		}
		ssrc++;
	}
	*dest = '\0';
	return (dlen + (ssrc - src));
}
