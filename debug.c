/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 07:00:22 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 08:13:29 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		debug_pass(void)
{
	if (g_debug)
		return (1);
	if (g_verbose)
		return (1);
	return (0);
}

void	debug(char *str, char *val, int ival)
{
	char	*sval;

	if (!g_debug)
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

void	debug_str(char *str)
{
	if (!g_debug)
		return ;
	ft_putstr(str);
	ft_putstr("\n");
	return ;
}
