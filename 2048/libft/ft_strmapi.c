/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:34:09 by apilate           #+#    #+#             */
/*   Updated: 2013/12/13 14:39:51 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		result[count] = f(count, *s);
		s++;
		count++;
	}
	return (result);
}
