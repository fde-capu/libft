/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:34:40 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/23 01:56:27 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isneedle(char *h, char *n)
{
	while ((*h == *n) && *h)
	{
		h++;
		n++;
	}
	return (*n ? 0 : 1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	int		nl;

	if (!*needle)
		return ((char *)haystack);
	h = (char *)haystack;
	n = (char *)needle;
	nl = 0;
	while (*++n)
		nl++;
	n = (char *)needle;
	while ((*h) && --len)
	{
		if ((isneedle(h, n)) && ((int)len - nl > 0))
			return (h);
		h++;
	}
	return (NULL);
}
