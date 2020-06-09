/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 08:25:41 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 10:02:09 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_is_comment
** Besides returning the answer, trims `*str`.
*/

int	ft_is_comment(char **str)
{
	*str = ft_strtrim(*str, TRIM_SET);
	return (ft_chrinset(*str, COMMENT_SET) ? 1 : 0);
}
