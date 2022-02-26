/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:46:48 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/25 22:35:54 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Frees to_free, returns to_return.
*/

void	*ft_xlloc(void *to_free, void *to_return)
{
	if (to_free)
		free(to_free);
	return (to_return);
}

void	*ft_x(void *to_free, void *to_return)
{
	return (ft_xlloc(to_free, to_return));
}
