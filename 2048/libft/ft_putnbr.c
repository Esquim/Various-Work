/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/03 16:32:24 by apilate           #+#    #+#             */
/*   Updated: 2013/12/17 14:56:09 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

int		ft_putnbr(int n)
{
	char	*toput;
	int		toreturn;

	toreturn = 0;
	toput = ft_itoa(n);
	if (toput == NULL)
		return (-1);
	toreturn = ft_putstr(toput);
	free(toput);
	return (toreturn);
}
