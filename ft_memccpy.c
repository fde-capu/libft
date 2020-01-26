/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 22:48:45 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/23 01:59:49 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_static_memchr(const void *s, int c, size_t n)
{
	const char	*r;
	size_t		ns;

	r = (const char *)s;
	ns = 0;
	while (ns++ < n)
		if (r[ns] == c)
			return ((void *)&r[ns]);
	return (NULL);
}

static void	*ft_static_memcpy(void *restrict dst, \
		const void *restrict src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

void		*ft_memccpy(void *restrict dst, const void *restrict src, int c, \
		size_t n)
{
	void	*p;

	p = ft_static_memchr(src, c, n);
	if (p != NULL)
		return (ft_static_memcpy(dst, src, p - src + 1) + (p - src + 1));
	ft_static_memcpy(dst, src, n);
	return (NULL);
}
