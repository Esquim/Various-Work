/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 16:57:09 by dtortera          #+#    #+#             */
/*   Updated: 2014/05/04 17:48:10 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stddef.h>
#include <unistd.h>
#include <libft.h>

char			*ft_strerror(int errnum)
{
	char						*err_msg;
	extern const char *const	sys_errlist[];
	extern const int			sys_nerr;

	if (errnum < 0 || errnum >= sys_nerr)
	{
		errno = EINVAL;
		return (ft_strjoin("Unknown error: ", ft_itoa(errnum)));
	}
	err_msg = (char*)sys_errlist[errnum];
	return (err_msg);
}

void			ft_perror(const char *s)
{
	char	*err_str;

	if (s && *s != '\0')
	{
		write(2, s, ft_strlen(s));
		write(2, ": ", 2);
	}
	err_str = ft_strerror(errno);
	write(2, err_str, ft_strlen(err_str));
	write(2, "\n", 1);
}
