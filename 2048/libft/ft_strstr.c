/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/23 14:41:43 by apilate           #+#    #+#             */
/*   Updated: 2013/12/01 13:52:46 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*tmp_strstr(char *str, char *to_find, char *a, char *b)
{
	b = to_find;
	while (*str != '\0')
	{
		if (*str != *b)
		{
			str++;
			continue ;
		}
		a = str;
		while (1)
		{
			if (*b == '\0')
				return (str);
			if (*a++ != *b++)
			{
				str++;
				break ;
			}
		}
		b = to_find;
	}
	return (NULL);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	char	*a;
	char	*b;
	char	*str;
	char	*to_find;

	a = 0;
	b = 0;
	str = (char*)s1;
	to_find = (char*)s2;
	if (to_find == NULL)
		return (NULL);
	if (*to_find == '\0')
		return (str);
	return (tmp_strstr(str, to_find, a, b));
}
