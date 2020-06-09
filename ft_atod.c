/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:53:17 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 14:24:12 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *str)
{
	char	*n;
	int		lod;
	int		rod;
	double	dec;

	n = ft_strdup(str);
	lod = ft_atoi(n);
	rod = ft_atoi(ft_strnchr(n, '.') + 1);
	dec = rod / (pow(10, ft_countdigits(rod)));
	free(n);
	return (lod + dec);
}
