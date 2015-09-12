/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:34:50 by apilate           #+#    #+#             */
/*   Updated: 2013/12/02 14:16:36 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = (char*)malloc(sizeof(*result)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, s1);
	ft_strlcat(result, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (result);
}
