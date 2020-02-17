/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:00:04 by fde-capu          #+#    #+#             */
/* U20200214155217 |:::||                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long n)
{
	unsigned int	len;
	char			*w;
	long long		t;
	char			*r;

	t = n < 0 ? n * -1 : n;
	len = n < 0 ? 2 : 1;
	while (t /= 10)
		len++;
	r = ft_calloc(sizeof(char) * (len + 1), 1);
	if (!r)
		return (NULL);
	w = r + len;
	*w-- = 0;
	*w = '0';
	if (!n)
		return (r);
	t = n < 0 ? n * -10 : n * 10;
	while (t /= 10)
		*w-- = (t % 10) + '0';
	if (n < 0)
		*w = '-';
	return (r);
}
