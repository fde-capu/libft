/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:29:16 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 00:40:51 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

long long	ft_atoi(const char *str)
{
	char		*a[2];
	char		*b;
	int			l;
	long long	r;
	int			neg;

	a[0] = ft_strtrim((char *)str, " \t\n\r\v\f");
	a[1] = a[0];
	neg = *a[1] == '-' ? 1 : 0;
	a[1] += *a[1] == '-' || *a[1] == '+' ? 1 : 0;
	b = a[1];
	l = 0 + st_sum_dign(a[1]);
	a[1] += st_sum_dign(a[1]);
	r = 0;
	a[1] = b;
	while ((l--) && (ft_isdigit(*a[1])))
	{
		r += (*a[1] - '0');
		if (((!neg) && (r > INT_MAX)) || ((neg) && (r * -1 < INT_MIN)))
			return (!neg ? -1 : 0);
		r *= l ? 10 : 1;
		a[1]++;
	}
	r *= neg ? -1 : 1;
	free(a[0]);
	return (r);
}
