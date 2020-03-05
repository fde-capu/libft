/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ucase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:24:12 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/05 04:28:43 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns allocated char* upper-cased.
*/
char	*ft_ucase(char *str)
{
	char	*dst;
	int		i;

	dst = ft_calloc(ft_strlen(str) + 1, 1);
	i = 0;
	while (str[i])
	{
		dst[i] = ft_toupper(str[i]);
		i++;
	}
	return (dst);
}
