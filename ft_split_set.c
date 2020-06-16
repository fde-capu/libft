/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 07:05:10 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/16 07:16:11 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*setstc_skip_c(char *s, const char *c)
{
	while ((*s) && (ft_chrinset(s, c)))
		s++;
	return (s);
}

static int	setstc_count(char *s, const char *c)
{
	int	n;

	n = 0;
	s = setstc_skip_c((char *)s, c);
	if ((*s) && !ft_chrinset(s, c))
		n++;
	while ((*s) && !ft_chrinset(s, c))
		s++;
	return (*s ? n + setstc_count(s, c) : n);
}

static int	setstc_len(char *s, const char *c)
{
	int	n;

	n = 0;
	while ((*s) && !ft_chrinset(s, c))
	{
		s++;
		n++;
	}
	return (n);
}

/*
** The use of ft_strlen is cheap solution.
*/

char		**ft_split_set(char const *s, const char *c)
{
	char	**spl;
	char	*z;
	int		i;
	int		w;

	z = (char *)s;
	spl = (char **)ft_calloc(sizeof(char *) * (setstc_count(z, c) + 1), 1);
	if (!spl)
		return (NULL);
	i = 0;
	while ((*z) && (ft_chrinset(z, c)))
		z++;
	while (*z)
	{
		spl[i] = (char *)ft_calloc(setstc_len(z, c) + 1, 1);
		if (!spl[i])
			return (NULL);
		w = 0;
		while ((*z) && (!ft_chrinset(z, c)))
			spl[i][w++] = *z++;
		i++;
		while ((*z) && (ft_chrinset(z, c)))
			z++;
	}
	return (spl);
}
