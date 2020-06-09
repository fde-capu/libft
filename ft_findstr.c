/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 20:25:22 by fde-capu          #+#    #+#             */
/*   Updated: 2020/05/19 20:25:25 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** returns the position of a string if found
**  or -1 if not found
*/

int		ft_findstr(char *str, char c)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (str[i] == c)
		return (i);
	return (-1);
}
