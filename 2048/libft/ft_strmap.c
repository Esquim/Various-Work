/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:34:03 by apilate           #+#    #+#             */
/*   Updated: 2013/12/01 13:39:58 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		count;

	if (s == NULL || f == NULL)
		return (NULL);
	count = 0;
	result = (char*)malloc(sizeof(*result) * ft_strlen(s));
	if (result == NULL)
		return (NULL);
	while (*s)
	{
		result[count] = f(*s);
		s++;
		count++;
	}
	return (result);
}
