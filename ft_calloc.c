/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 01:41:55 by fde-capu          #+#    #+#             */
/* U20200126132009 :||:|:                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;

	if (count <= 0 || size <= 0)
	{
		count = 1;
		size = 1;
	}
	c = malloc(count * size);
	if (c)
	{
		ft_bzero(c, count * size);
	}
	return (c);
}
