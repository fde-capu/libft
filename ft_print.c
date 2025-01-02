/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:13:45 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/23 12:45:19 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print(const char *str)
{
	write(1, str, ft_strlen(str));
	return ;
}

void	ft_print_stdout(const char *str)
{
	write(1, str, ft_strlen(str));
	return ;
}

void	ft_print_x(char *str)
{
	ft_print_stdout((const char *)str);
	free(str);
	return ;
}

void	str_replace_chr_chr(char **str, char this, char to_this)
{
	char	*h;

	h = *str;
	while (*h)
	{
		if (*h == this)
			*h = to_this;
		h++;
	}
	return ;
}

int		ft_print2_and_return_int(char *messageA, char *messageB, int return_value)
{
	ft_print(messageA);
	ft_print(messageB);
	ft_print("\n");
	return return_value;
}

int		ft_print_and_return_int(char *message, int return_value)
{
	ft_print(message);
	return return_value;
}
