/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 07:00:22 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 11:07:16 by fde-capu         ###   ########.fr       */
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

void	debug(char *str, char *val, int *ival)
{
	if (!debug_pass())
		return ;
	return (debug_body(str, val, *ival));
}

void	debug_str_only(char *str)
{
	if (!debug_pass())
		return ;
	ft_putstr(str);
	ft_putstr("\n");
	return ;
}

void	debug_str(char *str, char *val)
{
	return (debug(str, val, NULL));
}

void	debug_int(char *str, int val)
{
	return (debug(str, NULL, &val));
}
