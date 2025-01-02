/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfree2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 11:26:36 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/23 12:16:43 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strfree2d(char **str)
{
	char	**p;

	p = str;
	while (*p)
		free(*p++);
	free(str);
	return ;
}

bool	ft_strfree2d_and_return_bool(char **str, bool ret_val)
{
	ft_strfree2d(str);
	return ret_val;
}
