/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 13:59:19 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/02 13:21:15 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strx
** Usage: new_str = ft_strx(new_val, str_to_free);
** Usually: str = (new_str, str);
*/

char	*ft_strx(char *s1, char *s2)
{
	char	*x1;
	char	*x2;

	x1 = s1;
	x2 = s2;
	s2 = ft_strdup(s1);
	free(x1);
	free(x2);
	return (s2);
}
