/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:35:07 by apilate           #+#    #+#             */
/*   Updated: 2014/05/03 14:46:18 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <libft.h>

static void	*ft_rloc(void *p, size_t oldsz, size_t newsz)
{
	void	*np;

	np = malloc(newsz);
	if (np == NULL)
	{
		return (NULL);
	}
	if (p != NULL && oldsz != 0)
	{
		ft_memcpy(np, p, oldsz);
	}
	return (np);
}

static int	ft_strllen(const char *s, int c)
{
	int		i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**t;
	char	*tmp;
	int		co;

	co = 0;
	t = NULL;
	while (*s == c)
		s++;
	while (*s)
	{
		tmp = (char*)malloc(sizeof(*tmp) * ft_strllen(s, c) + 1);
		t = (char**)ft_rloc(t, co * sizeof(char*), (co + 1) * sizeof(char*));
		if (tmp == NULL || t == NULL)
			return (NULL);
		ft_strncpy(tmp, (char*)s, ft_strllen(s, c));
		tmp[ft_strllen(s, c)] = '\0';
		s += ft_strllen(s, c);
		t[co++] = tmp;
		while (*s == c)
			s++;
	}
	t = (char**)ft_rloc(t, co * sizeof(char*), (co + 1) * sizeof(char*));
	t[co] = 0;
	return (t);
}
