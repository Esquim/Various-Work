/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/03 19:02:17 by apilate           #+#    #+#             */
/*   Updated: 2013/12/17 14:56:26 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <libft.h>

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*s;

	s = malloc(sizeof(*s) * 20);
	if (s == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		s = ft_strcpy(s, "-2147483648");
		return (s);
	}
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	s[i++] = n % 10 + '0';
	while ((n /= 10) > 0)
	{
		s[i++] = n % 10 + '0';
	}
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	return (ft_strrev(s));
}
