/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:17:37 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/23 01:55:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_isinset(char a, char const *set)
{
	char	*r;

	r = (char *)set;
	while (*r)
	{
		if (*r == a)
			return (1);
		r++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	int		c;
	char	*m;
	char	*ma;

	c = 0;
	r = (char *)s1;
	while (st_isinset(*r, set))
		r++;
	while ((*++r) && (++c))
		;
	while ((*--r) && (st_isinset(*r, set)) && (--c))
		;
	c++;
	r = (char *)s1;
	while (st_isinset(*r, set))
		r++;
	ma = malloc(sizeof(char) * (c + 1));
	m = ma;
	while (c--)
		*m++ = *r++;
	*m = 0;
	return (ma);
}
