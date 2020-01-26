/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:05:18 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/23 01:57:13 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, \
		size_t dstsize)
{
	char *restrict			d;
	const char *restrict	s;
	size_t					t;
	int						p;

	d = dst;
	s = src;
	t = dstsize;
	if (t)
	{
		p = 1;
		while ((--t) && p)
		{
			*d++ = *s++;
			p = *(d - 1) ? 1 : 0;
		}
	}
	if (!t)
	{
		if (dstsize)
			*d = 0;
		while (*s++)
			;
	}
	return (s - src - 1);
}
