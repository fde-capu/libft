/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:31:57 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/22 16:46:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** In case of finding the "test", ft_args return a pointer to the next argv,
** or to the found argv if it is the last one.
*/

char	*ft_args(int argc, char **argv, char *test)
{
	argc--;
	while (argc)
	{
		if (ft_stridentical(argv[argc], test))
			return (argv[argc + 1] ? argv[argc + 1] : argv[argc]);
		argc--;
	}
	return (0);
}

bool	validate_args(int argc, char **argv, int argc_min, int argc_max, char **valid_args)
{
	char **va;
	if (argc < argc_min || argc > argc_max)
		return false;
	while (argc)
	{
		va = valid_args;
		while (*va)
		{
			if (ft_stridentical(argv[argc], *va))
				return true;
			va++;
		}
		argc--;
	}
	return false;
}
