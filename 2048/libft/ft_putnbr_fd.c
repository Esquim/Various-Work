/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:36:08 by apilate           #+#    #+#             */
/*   Updated: 2013/12/13 15:50:10 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

int		ft_putnbr_fd(int n, int fd)
{
	char	*toput;
	int		toreturn;

	toreturn = 0;
	toput = ft_itoa(n);
	if (toput == NULL)
		return (-1);
	toreturn = ft_putstr_fd(toput, fd);
	free(toput);
	return (toreturn);
}
