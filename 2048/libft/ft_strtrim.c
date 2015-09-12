/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:34:59 by apilate           #+#    #+#             */
/*   Updated: 2013/12/13 14:40:50 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

static int	ft_istotrim(char s)
{
	return (s == ' ' || s == '\t' || s == '\n');
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*result;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (*s && ft_istotrim(*s))
		s++;
	i = ft_strlen(s);
	while (*s && ft_istotrim(s[--i]))
		;
	i++;
	result = (char*)malloc(sizeof(*result) * i);
	ft_strncpy(result, (char*)s, i);
	result[i] = '\0';
	return (result);
}
