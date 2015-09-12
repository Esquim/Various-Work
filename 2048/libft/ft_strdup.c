/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:36:17 by apilate           #+#    #+#             */
/*   Updated: 2014/01/06 14:17:00 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;

	if (s1 == NULL)
		return (NULL);
	dest = malloc(sizeof(*dest) * (ft_strlen(s1) + 1));
	ft_strcpy(dest, s1);
	return (dest);
}
