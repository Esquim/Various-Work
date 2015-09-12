/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2013/11/28 18:32:33 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	i;

	if (*s2 == '\0')
	{
		return ((char*)s1);
	}
	len = ft_strlen(s2);
	i = 0;
	while (s1[i] && (i + len) <= n)
	{
		if (ft_strncmp(s1 + i, s2, len) == 0)
			return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
