/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:03:33 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/23 01:58:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*w;
	char			*r;
	unsigned int	c;
	char			*m;
	char			*mw;

	w = (char *)s1;
	while ((*++w) && (++c))
		;
	r = (char *)s2;
	while ((*++r) && (++c))
		;
	m = malloc(sizeof(char) * (c + 2));
	if (!m)
		return (NULL);
	mw = m;
	w = (char *)s1;
	while (*w)
		*mw++ = *w++;
	r = (char *)s2;
	while (*r)
		*mw++ = *r++;
	*mw = 0;
	return (m);
}
