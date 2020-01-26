/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:00:04 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/23 22:01:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*w;
	long	t;
	char	*r;

	t = n < 0 ? (long)n * -1 : (long)n;
	len = n < 0 ? 2 : 1;
	while (t /= 10)
		len++;
	r = malloc(sizeof(char) * len);
	w = r + len;
	*w-- = 0;
	*w = '0';
	if (!n)
		return (r);
	t = n < 0 ? (long)n * -1 : (long)n;
	while (t)
	{
		*w = (t % 10) + '0';
		w--;
		t /= 10;
	}
	if (n < 0)
		*w = '-';
	return (r);
}
