/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 00:25:24 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/23 01:16:26 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	char	*a;
	char	*b;
	int		l;
	int		r;
	int		neg;

	a = ft_strtrim((char *)str, " \t\n\r\v\f");
	neg = *a == '-' ? 1 : 0;
	a += *a == '-' || *a == '+' ? 1 : 0;
	b = a;
	l = 1;
	while (ft_isdigit(*++a))
		l++;
	r = 0;
	a = b;
	while ((l--) && (ft_isdigit(*a)))
	{
		r += (*a - '0');
		if (l)
			r *= 10;
		a++;
	}
	r *= neg ? -1 : 1;
	return (r);
}
