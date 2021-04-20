/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfree2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 11:26:36 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/08 23:17:48 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_strfree2d(char **str)
{
	char	**p;

	p = str;
	while (*p)
		free(*p++);
	free(str);
	return ;
}
