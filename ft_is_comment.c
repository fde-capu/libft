/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 08:25:41 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 10:40:14 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_comment(char *str)
{
	char	*tstr;
	int		rv;

	tstr = ft_strtrim(str, TRIM_SET);
	rv = ft_chrinset(tstr, COMMENT_SET) ? 1 : 0;
	free(tstr);
	return (rv);
}
