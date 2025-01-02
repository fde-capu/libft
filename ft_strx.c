/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 13:59:19 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/25 22:36:37 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strx
** Usage: new_str = ft_strx(new_val, str_to_free);
** Usually: str = (new_str, str);
*/

char	*ft_strx(char *to_clone, char *to_free)
{
	return (ft_x(to_free, ft_strdup(to_clone)));
}
