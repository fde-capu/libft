/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:03:33 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/27 16:19:16 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*w;
	char			*r;
	char			*m;
	char			*mw;

	m = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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

str		ft_strjoin2d(str* s, str divisor)
{
	str* h = s;
	str out = ft_str("");
	while (*h)
	{
		out = ft_strcatxx(out, ft_strcat_variadic(2, *h++, divisor));
	}
	return out;
}
