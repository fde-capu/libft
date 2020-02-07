/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 00:25:24 by fde-capu          #+#    #+#             */
/* U20200207125002 :|||:|                      */
/*                                                                            */
/* ************************************************************************** */
//test
#include "libft.h"
#ifndef INT_MAX
# define INT_MAX 2147483647
#endif
#ifndef INT_MIN
# define INT_MIN -2147483648
#endif

static int	st_sum_dign(char *a)
{
	int	s;

	s = 0;
	while (ft_isdigit(*a))
	{
		s++;
		a++;
	}
	return (s);
}

int			ft_atoi(const char *str)
{
	char	*a;
	char	*b;
	int		l;
	long	r;
	int		neg;

	a = ft_strtrim((char *)str, " \t\n\r\v\f");
	neg = *a == '-' ? 1 : 0;
	a += *a == '-' || *a == '+' ? 1 : 0;
	b = a;
	l = 0 + st_sum_dign(a);
	a += st_sum_dign(a);
	r = 0;
	a = b;
	while ((l--) && (ft_isdigit(*a)))
	{
		r += (*a - '0');
		if (((!neg) && (r > INT_MAX)) || ((neg) && (r * -1 < INT_MIN)))
			return (!neg ? -1 : 0);
		r *= l ? 10 : 1;
		a++;
	}
	r *= neg ? -1 : 1;
	return ((int)r);
}
