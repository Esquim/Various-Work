/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:33:13 by apilate           #+#    #+#             */
/*   Updated: 2013/11/22 15:33:14 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	size += 1;
	str = (char*)malloc(size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
