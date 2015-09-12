/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:49:05 by apilate           #+#    #+#             */
/*   Updated: 2013/11/21 16:49:07 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		pos;
	size_t		pos2;

	pos = ft_strlen(s1);
	pos2 = 0;
	while (*s2 && pos2 < n)
	{
		s1[pos] = *s2;
		pos++;
		pos2++;
		s2++;
	}
	s1[pos] = '\0';
	return (s1);
}
