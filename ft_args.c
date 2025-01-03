/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:31:57 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/24 19:07:16 by fde-capu         ###   ########.fr       */
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

bool	validate_args(int argc, char **argv, int argc_min, int argc_max, char *valid_args_csv)
{
	char **valid_args = ft_split(valid_args_csv, ',');
	char **va;

	if (argc < argc_min || argc > argc_max)
		return ft_strfree2d_and_return_bool(valid_args, false);
	while (--argc)
	{
		va = valid_args;
		while (*va)
		{
			if (ft_stridentical(argv[argc], *va))
				return ft_strfree2d_and_return_bool(valid_args, true);
			*va += 1;
		}
	}
	return ft_strfree2d_and_return_bool(valid_args, false);
}

bool	validate_args_regex(int argc, char **argv, int argc_min, int argc_max, char *valid_args_regex_pipesv)
{
	char **valid_args = ft_split(valid_args_regex_pipesv, '|');
	char **va;
	if (argc < argc_min || argc > argc_max)
		return ft_strfree2d_and_return_bool(valid_args, false);
	while (--argc)
	{
		va = valid_args;
		while (*va)
		{
			if (ft_check_full(argv[argc], *va))
				return ft_strfree2d_and_return_bool(valid_args, true);
			*va += 1;
		}
	}
	return ft_strfree2d_and_return_bool(valid_args, false);
}
