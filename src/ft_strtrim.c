/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:17:37 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/29 10:42:20 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		st_inset(char *r, char const *set)
{
	char	*s;

	s = (char *)set;
	while (*s)
	{
		if (*s == *r)
			return (1);
		s++;
	}
	return (0);
}

static char		*st_trimstart(char const *s1, char const *set)
{
	char	*r;

	r = (char *)s1;
	while ((*r) && (st_inset(r, set)))
		r++;
	return (r);
}

static size_t	st_trimlen(char const *s1, char const *set)
{
	size_t	l;
	char	*r;

	r = st_trimstart(s1, set);
	l = 0;
	while (*r)
	{
		r++;
		l++;
	}
	r--;
	while ((l) && (st_inset(r, set)))
	{
		r--;
		l--;
	}
	return (l);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*m;
	size_t	l;
	char	*w;
	char	*r;

	l = st_trimlen(s1, set);
	m = malloc(l + 1);
	if (!m)
		return (NULL);
	w = m;
	r = st_trimstart(s1, set);
	while ((l) && (*r))
	{
		*w = *r;
		w++;
		r++;
		l--;
	}
	*w = 0;
	return (m);
}
