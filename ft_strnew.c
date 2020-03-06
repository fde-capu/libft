/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 01:47:38 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/06 08:11:58 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(const char *str)
{
	char	*new;

	new = ft_calloc(ft_strlen(str) + 1, 1);
	if (!new)
		return (NULL);
	return (ft_strcpy(new, str));
}
