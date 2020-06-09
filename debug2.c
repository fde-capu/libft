/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:04:45 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 11:07:46 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	debug_body(char *str, char *val, int ival)
{
	char	*sval;

	if (!debug_pass())
		return ;
	sval = ft_itoa(ival);
	ft_putstr(str);
	ft_putstr(DEB_DIV);
	ft_putstr(val);
	ft_putstr(DEB_DIV);
	ft_putstr(sval);
	ft_putstr("\n");
	free(sval);
	return ;
}


