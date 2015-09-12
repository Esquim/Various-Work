/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:31:05 by apilate           #+#    #+#             */
/*   Updated: 2013/11/19 14:31:06 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strrev(char *src)
{
	int		i;
	int		j;
	char	c;
	char	*reverse;

	reverse = malloc(ft_strlen(src) * sizeof(reverse));
	ft_strcpy(reverse, src);
	i = 0;
	j = ft_strlen(reverse) - 1;
	while (i < j)
	{
		c = reverse[i];
		reverse[i] = reverse[j];
		reverse[j] = c;
		i++;
		j--;
	}
	return (reverse);
}
