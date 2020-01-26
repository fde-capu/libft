/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:28:21 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/23 01:59:30 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*r;
	size_t		ns;

	r = (const char *)s;
	ns = 0;
	while (ns < n)
		if (r[ns] == c)
			return ((void *)&r[ns]);
		else
			ns++;
	return (NULL);
}
